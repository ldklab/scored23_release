# ------------------------------------------------------------------------
# This file is to loop the ASTAndLexParse.py file for all the files in the datasets
# ------------------------------------------------------------------------

import os
import subprocess
import argparse

controlfolderlist = []
autopilotfolderlist = []

controlfilelist = []
autopilotfilelist = []


# ---------------------------------------------------
# To Parse All Data Files in Control Folder
# ---------------------------------------------------


def parseControlFolder(controlfolder, dictionaryFolderPath):
    for folders in os.listdir(controlfolder):
        # print(folders)
        if not folders == ".DS_Store":
            controlfolderlist.append(os.path.join(controlfolder, folders))
    # print(len(controlfolderlist))

    for eachSubFolder in controlfolderlist:
        for files in os.listdir(eachSubFolder):
            if not files == ".DS_Store":
                controlfilelist.append(os.path.join(eachSubFolder, files))

    # print(len(controlfilelist))
    # print(dictionaryFolderPath)

    for x in controlfilelist:
        subprocess.run(["python3", "ASTandLexParse.py", x, dictionaryFolderPath])


    # ---------------------------------------------------
    # To Parse All Data Files in Autopilot Folder
    # ---------------------------------------------------


def parseAutopilotFolder(autopilotfolder, dictionaryFolderPath):
    for folders in os.listdir(autopilotfolder):
        if not folders == ".DS_Store":
            autopilotfolderlist.append(os.path.join(autopilotfolder, folders))

    for eachSubFolder in autopilotfolderlist:
        for files in os.listdir(eachSubFolder):
            if not files == ".DS_Store":
                autopilotfilelist.append(os.path.join(eachSubFolder, files))

    # print(len(autopilotfilelist))

    for x in autopilotfilelist:
        subprocess.run(["python3", "ASTandLexParse.py", x, dictionaryFolderPath])


    # ---------------------------------------------------
    # ---------------- MAIN STARTS HERE -----------------
    # ---------------------------------------------------


def main():
    inputArgument = argparse.ArgumentParser()

    inputArgument.add_argument(
        "sourcefolder", help="Add absolute path to the Dataset folder"
    )
    inputArgument.add_argument(
        "dictionary",
        help="Add absolute path to dictionary folder, either Bigram, Trigram or Quadgram",
    )

    args = inputArgument.parse_args()

    datasetFolderPath = args.sourcefolder
    dictionaryFolderPath = args.dictionary

    for folder in os.listdir(datasetFolderPath):
        if folder == "Control":
            SourceControlDataFolder = os.path.join(datasetFolderPath, folder)
        if folder == "Autopilot":
            SourceAutopilotDataFolder = os.path.join(datasetFolderPath, folder)

    # print(SourceControlDataFolder)
    # print(SourceAutopilotDataFolder)
    # print(dictionaryFolderPath)

    # ---------------------------------------------------
    # To Loop through All Data Files in Control Folder and send dictionary Path
    # ---------------------------------------------------

    parseControlFolder(SourceControlDataFolder, dictionaryFolderPath)

    # # ---------------------------------------------------
    # # To Loop through All Data Files in Autopilot Folder and send dictionary Path
    # # ---------------------------------------------------

    parseAutopilotFolder(SourceAutopilotDataFolder, dictionaryFolderPath)


if __name__ == "__main__":
    main()
