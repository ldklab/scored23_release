import argparse
import os
import pickle
import statistics
import math
import re
import pymongo


def createASTVector(PathToPickleFile):
    with open(PathToPickleFile, "rb") as inF:
        eachFunctionDict = pickle.load(inF)

    x = eachFunctionDict.values()
    funcValues = list(x)

    newList = []

    for eachentry in funcValues:
        if eachentry != 0.0:
            newList.append(eachentry)

        normalizingFactor = sum(newList)

        outputVector = []

    for eachentry in funcValues:
        outputVector.append(eachentry / normalizingFactor)

    return outputVector


def createLexicalFeatureDictionary(filePath):
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

    return endDict


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


def createVector(endDict):
    featureValues = endDict.values()
    y = list(featureValues)
    return y


def saveToMongo(
    combinedVector,
    codedBy,
    filePath,
    rootFolder,
    parentFolder,
    filename,
    PathToPickleFile,
    ASTFolder,
):
    # print(combinedVector, codedBy, filePath, rootFolder, parentFolder, filename, PathToPickleFile)

    # -------------------------------------------------------
    # convert to string format to save in DB
    # -------------------------------------------------------

    inStringFormat = str(combinedVector)

    # -------------------------------------------------------
    # Mongo db initialization commands
    # -------------------------------------------------------

    myclient = pymongo.MongoClient("mongodb://localhost:27017/")

    mydb = myclient["CodeStylometry"]

    db_name = "CombinedVectorWith" + ASTFolder

    mycol = mydb[db_name]

    # -------------------------------------------------------
    # Defining the insert query to insert in mongodb as a record
    # -------------------------------------------------------

    insertDocument = {
        "File_Name": filename,
        "Coded_By": codedBy,
        "Parent_Folder": parentFolder,
        "File_Path": filePath,
        "AST_Path": PathToPickleFile,
        "AST_Dictionary": ASTFolder,
        "Output_Vector": inStringFormat,
    }

    # -------------------------------------------------------
    # running the insert query in mongodb
    # -------------------------------------------------------

    x = mycol.insert_one(insertDocument)




# ---------------------------------------------------
# ---------------- MAIN STARTS HERE -----------------
# ---------------------------------------------------


def main():
    cmdparser = argparse.ArgumentParser()
    cmdparser.add_argument(
        "codeFile", help="Add absolute path to the file that needs to be parsed"
    )
    cmdparser.add_argument(
        "ASTDict", help="Add absolute path to the Bigram folder that needs to be parsed"
    )

    args = cmdparser.parse_args()

    # ------------------------------------------------------------
    # Parse the input .. One is absolute path to
    # ------------------------------------------------------------

    dictPath = args.ASTDict

    filePath = args.codeFile

    splittedPath = filePath.split("/")

    rootFolder = splittedPath[-3]
    parentFolder = splittedPath[-2]
    filename = os.path.splitext(splittedPath[-1])[0]

    ASTFolder = dictPath.split("/")[-1]

    # print(ASTFolder)

    if rootFolder == "Autopilot":
        codedBy = "Machine"
    if rootFolder == "Control":
        codedBy = "Human"

    PathToPickleFile = os.path.join(dictPath, rootFolder, parentFolder, filename)

    # ------------------------------------------------------------
    # Create Bigram Vector of the file using Pickle file
    # ------------------------------------------------------------

    ASTVector = createASTVector(PathToPickleFile)
    # print(len(ASTBigramVector))
    # print(type(ASTBigramVector))
    # print(ASTBigramVector)

    # -------------------------------------------------
    # Function : Create lexical feature vector with all features
    # -------------------------------------------------

    endDict = createLexicalFeatureDictionary(filePath)
    # print(endDict)

    # -------------------------------------------------
    # Function : Create feature vector with all the above values
    # -------------------------------------------------

    endLexicalVector = createVector(endDict)
    # print(len(endLexicalVector))
    # print(type(endLexicalVector))
    # print(endLexicalVector)

    # -------------------------------------------------
    # Create feature vector with AST + Lexical Vectors
    # -------------------------------------------------

    combinedVector = ASTVector + endLexicalVector
    # print(combinedVector)
    # print(len(combinedVector))
    # print(type(combinedVector))

    # -------------------------------------------------
    # Function : Save feature vector to mongodb
    # -------------------------------------------------

    saveToMongo(
        combinedVector,
        codedBy,
        filePath,
        rootFolder,
        parentFolder,
        filename,
        PathToPickleFile,
        ASTFolder,
    )


if __name__ == "__main__":
    main()
