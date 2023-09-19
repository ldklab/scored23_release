# ------------------------------------------------------------------------
# This file is to loop the LexicalParse.py file for all the files in the datasets
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


def parseControlFolder(controlfolder):
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

    for x in controlfilelist:
        subprocess.run(["python3", "LexicalParse.py", x])


    # ---------------------------------------------------
    # To Parse All Data Files in Autopilot Folder
    # ---------------------------------------------------


def parseAutopilotFolder(autopilotfolder):
    for folders in os.listdir(autopilotfolder):
        if not folders == ".DS_Store":
            autopilotfolderlist.append(os.path.join(autopilotfolder, folders))

    for eachSubFolder in autopilotfolderlist:
        for files in os.listdir(eachSubFolder):
            if not files == ".DS_Store":
                autopilotfilelist.append(os.path.join(eachSubFolder, files))

    # print(len(autopilotfilelist))

    for x in autopilotfilelist:
        subprocess.run(["python3", "LexicalParse.py", x])


    # ---------------------------------------------------
    # ---------------- MAIN STARTS HERE -----------------
    # ---------------------------------------------------


def main():
    inputArgument = argparse.ArgumentParser()

    inputArgument.add_argument(
        "sourcefolder", help="Add absolute path to the parent data folder"
    )
    # inputArgument.add_argument('destfolder', help='Add absolute path to destination folder')

    args = inputArgument.parse_args()

    parentFolderPath = args.sourcefolder
    # destFolderPath = args.destfolder

    for folder in os.listdir(parentFolderPath):
        if folder == "Control":
            SourceControlDataFolder = os.path.join(parentFolderPath, folder)
        if folder == "Autopilot":
            SourceAutopilotDataFolder = os.path.join(parentFolderPath, folder)

    # print(SourceControlDataFolder)
    # print(SourceAutopilotDataFolder)

    # ---------------------------------------------------
    # To Parse All Data Files in Control Folder
    # ---------------------------------------------------

    parseControlFolder(SourceControlDataFolder)

    # ---------------------------------------------------
    # To Parse All Data Files in Autopilot Folder
    # ---------------------------------------------------

    parseAutopilotFolder(SourceAutopilotDataFolder)


if __name__ == "__main__":
    main()
