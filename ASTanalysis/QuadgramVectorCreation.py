import os
import pickle
import pymongo
import argparse


def createVector(finalList):
    for eachFile in finalList:
        with open(eachFile, "rb") as inF:
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

        splitPath = eachFile.split("/")
        rootFolder = splitPath[-3]

        if rootFolder == "Autopilot":
            codedBy = "Machine"
        if rootFolder == "Control":
            codedBy = "Human"

        parentFolder = splitPath[-2]
        fileName = splitPath[-1]

        filePath = eachFile

        # -------------------------------------------------------
        # convert to string format to save in DB
        # -------------------------------------------------------

        inStringFormat = str(outputVector)

        # -------------------------------------------------------
        # Mongo db initialization commands
        # -------------------------------------------------------

        myclient = pymongo.MongoClient("mongodb://localhost:27017/")

        mydb = myclient["CodeStylometry"]

        mycol = mydb["ASTQuadgramVector"]

        # -------------------------------------------------------
        # Mongo db initialization commands end here
        # -------------------------------------------------------

        # -------------------------------------------------------
        # Defining the insert query to insert in mongodb as a record
        # -------------------------------------------------------

        insertDocument = {
            "File_Name": fileName,
            "Coded_By": codedBy,
            "Parent_Folder": rootFolder,
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
    cmdparser.add_argument("Source", help="Add path for the Quadgram Folder")
    # cmdparser.add_argument('destination')

    args = cmdparser.parse_args()

    parentFolder = args.Source
    # destPath = args.destination

    # ---------------------------------------------------
    # Define paths for Control and Autopilot folder
    # ---------------------------------------------------

    ControlFolder = os.path.join(parentFolder, "Control")
    AutoFolder = os.path.join(parentFolder, "Autopilot")

    # print(ControlFolder)
    # print(AutoFolder)

    autopilotfolderlist = []
    controlfolderlist = []

    for folders in os.listdir(AutoFolder):
        if not folders == ".DS_Store":
            autopilotfolderlist.append(os.path.join(AutoFolder, folders))

    autopilotfilelist = []

    for eachSubAutoFolder in autopilotfolderlist:
        for files in os.listdir(eachSubAutoFolder):
            if not files == ".DS_Store":
                autopilotfilelist.append(os.path.join(eachSubAutoFolder, files))

    # print(len(autopilotfilelist))
    # print((autopilotfilelist))

    for folders in os.listdir(ControlFolder):
        if not folders == ".DS_Store":
            controlfolderlist.append(os.path.join(ControlFolder, folders))

    controlfilelist = []
    # print(controlfolderlist)
    # print(len(controlfolderlist))

    for eachSubContFolder in controlfolderlist:
        for files in os.listdir(eachSubContFolder):
            if not files == ".DS_Store":
                controlfilelist.append(os.path.join(eachSubContFolder, files))

    # print(len(controlfilelist))
    # print((controlfilelist))

    finalList = autopilotfilelist + controlfilelist
    # print(len(finalList))

    # ---------------------------------------------------
    # Create Vector
    # ---------------------------------------------------

    createVector(finalList)



if __name__ == "__main__":
    main()
