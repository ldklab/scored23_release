import os
import argparse
import statistics
import math
import re
import pymongo

# -------------------------------------------------
# Function : Calculate Avegrage Length of lines
# -------------------------------------------------


def averageLineLength(filePath):
    fn = open(filePath, "r")
    lines = fn.readlines()

    # print(len(lines))
    # print(type(lines))
    # for line in lines:
    #     print(len(line.strip('\n')))
    # sum(len(line))

    return sum(len(line.strip("\n")) for line in lines) / len(lines)


# -------------------------------------------------
# Function : Calculate Standard Deviation of length of lines
# -------------------------------------------------


def stdDevOfLines(filePath):
    stdDevList = []

    fn = open(filePath, "r")
    lines = fn.readlines()
    for line in lines:
        stdDevList.append(len(line.strip("\n")))

    calculatedStdDev = statistics.stdev(stdDevList)

    return calculatedStdDev


# -------------------------------------------------
# Function : Calculate log of number of words in a function
# -------------------------------------------------


def countWords(filePath):
    num_words = 0

    fn = open(filePath, "r")
    for line in fn:
        words = line.split()
        num_words += len(words)

    logNumWords = math.log(num_words)
    # return(num_words)
    return logNumWords


# -------------------------------------------------
# Function : Calculate log of number of lines of comments
# -------------------------------------------------


def countComments(filePath):
    commentCounter = 0

    fn = open(filePath, "r")
    data = fn.read()
    numOfCharacters = len(data)

    lines = fn.readlines()

    # print(len(lines))

    for x in lines:
        eachLine = x.lstrip()
        if eachLine.startswith("//"):
            commentCounter += 1
            # print(eachLine)

    dividedByChar = commentCounter / numOfCharacters

    if commentCounter != 0:
        logofComment = math.log(dividedByChar)
        return logofComment
    else:
        return commentCounter


# -------------------------------------------------
# Function : Calculate number of keywords; do, else-if, if, else, switch, for or while
# -------------------------------------------------


def countKeywords(filePath):
    # numberoflines = 0

    file = open(filePath, "r")
    data = file.read()
    numOfCharacters = len(data)

    # print(numOfCharacters)

    keywordDict = {
        "do": 0.0,
        "else if": 0.0,
        "if": 0.0,
        "else": 0.0,
        "switch": 0.0,
        "for": 0.0,
        "while": 0.0,
    }

    file = open(filePath, "r")

    for word in file:
        if re.search("if", word):
            keywordDict["if"] = keywordDict["if"] + 1

    file = open(filePath, "r")

    for word in file:
        if re.search("else", word):
            keywordDict["else"] = keywordDict["else"] + 1

    file = open(filePath, "r")

    for word in file:
        if re.search("else if", word):
            keywordDict["else if"] = keywordDict["else if"] + 1

    file = open(filePath, "r")

    for word in file:
        if re.search("for", word):
            keywordDict["for"] = keywordDict["for"] + 1

    file = open(filePath, "r")

    for word in file:
        if re.search("do", word):
            keywordDict["do"] = keywordDict["do"] + 1

    file = open(filePath, "r")

    for word in file:
        if re.search("while", word):
            keywordDict["while"] = keywordDict["while"] + 1

    file = open(filePath, "r")

    for word in file:
        if re.search("switch", word):
            keywordDict["switch"] = keywordDict["switch"] + 1

    for key, value in keywordDict.items():
        keywordDict.update({key: (value / numOfCharacters)})

    for key, value in keywordDict.items():
        if value != 0:
            keywordDict.update({key: math.log(value)})

    return keywordDict


# -------------------------------------------------
# Function : Create dictionary with all the above values
# -------------------------------------------------


def createDict(averageline, stdDev, numOfWords, numOfComments, dictofKeywords):
    dictionaryOfVector = {
        "AverageLoL": averageline,
        "StandardDev": stdDev,
        "NumOfWords": numOfWords,
        "NumOfComments": numOfComments,
        "if-Occured": dictofKeywords["if"],
        "else-Occured": dictofKeywords["else"],
        "elseIf-Occured": dictofKeywords["else if"],
        "do-Occured": dictofKeywords["do"],
        "while-Occured": dictofKeywords["while"],
        "for-Occured": dictofKeywords["for"],
        "switch-Occured": dictofKeywords["switch"],
    }

    return dictionaryOfVector


# -------------------------------------------------
# Function : Create feature vector with all the above values
# -------------------------------------------------


def createVector(endDict):
    x = endDict.values()
    y = list(x)
    return y


# -------------------------------------------------
# Function : Save feature vector to pickle
# -------------------------------------------------

# def saveToPickle(endVector, writtenBy, fileName, parentFolder):

#     outputFolderPath = os.path.join('/Users/sbukhari/Sandbox/llmchaincopy/ASTanalysis/ExplexicalFeatures', writtenBy, parentFolder)
#     outputFilePath = os.path.join(outputFolderPath, fileName)

#     # print(outputFolderPath)

#     try:
#         os.makedirs(outputFolderPath, exist_ok=True)
#         with open(outputFilePath,"wb") as outFile:
#             pickle.dump(endVector, outFile)

#     except OSError as error:
#         print("unable to create")

#     return(outputFilePath)

# -------------------------------------------------
# Function : Save feature vector to mongodb
# -------------------------------------------------


def saveToMongo(endVector, writtenBy, fileName, parentFolder, filePath):
    # print(endVector, writtenBy, fileName, parentFolder, endFilePath)

    # -------------------------------------------------------
    # convert to string format to save in DB
    # -------------------------------------------------------

    inStringFormat = str(endVector)

    # -------------------------------------------------------
    # Mongo db initialization commands
    # -------------------------------------------------------

    myclient = pymongo.MongoClient("mongodb://localhost:27017/")

    mydb = myclient["CodeStylometry"]

    mycol = mydb["LexicalVectors"]

    # -------------------------------------------------------
    # Defining the insert query to insert in mongodb as a record
    # -------------------------------------------------------

    insertDocument = {
        "File_Name": fileName,
        "Coded_By": writtenBy,
        "Parent_Folder": parentFolder,
        "File_Path": filePath,
        "Output_Vector": inStringFormat,
    }

    # -------------------------------------------------------
    # running the insert query in mongodb
    # -------------------------------------------------------

    x = mycol.insert_one(insertDocument)




def main():
    cmdparser = argparse.ArgumentParser()
    cmdparser.add_argument(
        "file", help="Add absolute path to the file that needs to be parsed"
    )
    args = cmdparser.parse_args()

    filePath = args.file

    if "Control" in filePath:
        writtenBy = "Human"

    if "Autopilot" in filePath:
        writtenBy = "Machine"

    splittingFilePath = filePath.split("/")

    fileName = os.path.splitext(splittingFilePath[-1])[0]

    # print(fileName)

    parentFolder = splittingFilePath[-2]

    # -------------------------------------------------
    # Function : Calculate Avegrage Length of lines
    # -------------------------------------------------

    averageline = averageLineLength(filePath)
    # print(averageline)

    # -------------------------------------------------
    # Function : Calculate Avegrage Length of lines
    # -------------------------------------------------

    stdDev = stdDevOfLines(filePath)
    # print(stdDev)

    # -------------------------------------------------
    # Function : Calculate log of number of words in a function delimited by spaces only
    # -------------------------------------------------

    numOfWords = countWords(filePath)
    # print(numOfWords)

    # -------------------------------------------------
    # Function : Calculate log of number of lines of comments
    # -------------------------------------------------

    numOfComments = countComments(filePath)
    # print(numOfComments)

    # -------------------------------------------------
    # Function : Calculate number of keywords; do, else-if, if, else, switch, for or while
    # -------------------------------------------------

    dictofKeywords = countKeywords(filePath)
    # print(dictofKeywords)

    # -------------------------------------------------
    # Function : Create dictionary with all the above values
    # -------------------------------------------------

    endDict = createDict(averageline, stdDev, numOfWords, numOfComments, dictofKeywords)
    # print(endDict)

    # -------------------------------------------------
    # Function : Create feature vector with all the above values
    # -------------------------------------------------

    endVector = createVector(endDict)
    # print(endVector)

    # # -------------------------------------------------
    # # Function : Save feature vector to pickle
    # # -------------------------------------------------

    # endFilePath = saveToPickle(endVector, writtenBy, fileName, parentFolder)

    # -------------------------------------------------
    # Function : Save feature vector to mongodb
    # -------------------------------------------------

    # saveToMongo(endVector, writtenBy, fileName, parentFolder, endFilePath)
    saveToMongo(endVector, writtenBy, fileName, parentFolder, filePath)


if __name__ == "__main__":
    main()
