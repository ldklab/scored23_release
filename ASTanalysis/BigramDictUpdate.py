import argparse
import os
import pickle


# ---------------------------------------------------
# Update and Create a pickle file for each function in Control Folder
# ---------------------------------------------------


def funcOfControl(controlfilelist, destPath, pathToEmptyDict, dictFile):
    for eachPath in controlfilelist:
        splittedPath = eachPath.split("/")

        rootFolder = splittedPath[-3]
        parentFolder = splittedPath[-2]
        filename = os.path.splitext(splittedPath[-1])[0]

        with open(pathToEmptyDict, "rb") as inF:
            emptyDict = pickle.load(inF)

        with open(eachPath, "rb") as inF2:
            treeNodes = pickle.load(inF2)
        for i in range(len(treeNodes) - 1):
            index = dictFile[treeNodes[i]] + "$$" + dictFile[treeNodes[i + 1]]
            emptyDict[index] += 1.0

        dictionarypath = os.path.join(destPath, "Bigram", rootFolder, parentFolder)
        filenamepath = os.path.join(dictionarypath, filename)

        try:
            os.makedirs(dictionarypath, exist_ok=True)
            with open(filenamepath, "wb") as outF:
                pickle.dump(emptyDict, outF)
        except OSError as error:
            print("unable to create")




# ---------------------------------------------------
# Update and Create a pickle file for each function in Autopilot Folder
# ---------------------------------------------------


def funcOfAutopilot(autopilotfilelist, destPath, pathToEmptyDict, dictFile):
    for eachPath in autopilotfilelist:
        splittedPath = eachPath.split("/")

        rootFolder = splittedPath[-3]
        parentFolder = splittedPath[-2]
        filename = os.path.splitext(splittedPath[-1])[0]

        with open(pathToEmptyDict, "rb") as inF:
            emptyDict = pickle.load(inF)

        with open(eachPath, "rb") as inF2:
            treeNodes = pickle.load(inF2)

        for i in range(len(treeNodes) - 1):
            index = dictFile[treeNodes[i]] + "$$" + dictFile[treeNodes[i + 1]]
            emptyDict[index] += 1.0

        dictionarypath = os.path.join(destPath, "Bigram", rootFolder, parentFolder)
        filenamepath = os.path.join(dictionarypath, filename)

        try:
            os.makedirs(dictionarypath, exist_ok=True)
            with open(filenamepath, "wb") as outF:
                pickle.dump(emptyDict, outF)
        except OSError as error:
            print("unable to create")



def main():
    # ---------------------------------------------------
    # ---------------------------------------------------
    # Put the path for the Empty Bigram Dictionary file
    # ---------------------------------------------------
    # ---------------------------------------------------
    current_script_path = os.path.abspath(__file__)

    # Get the directory containing the current script
    current_script_directory = os.path.dirname(current_script_path)
    relative_pathToEmptyDict = "../Processed/EmptyDictionaries/dictOfBigram.pickle"

    absolute_pathToEmptyDict = os.path.join(current_script_directory, relative_pathToEmptyDict)

    # ---------------------------------------------------
    # ---------------------------------------------------
    # Put the path for the Empty Bigram Dictionary file
    # ---------------------------------------------------
    # ---------------------------------------------------

    # ---------------------------------------------------
    # ---------------------------------------------------
    # Put the path for DictOfNodes.py file
    # ---------------------------------------------------
    # ---------------------------------------------------
    relative_pathToDictOfNodes = "../Processed/DictOfNodes/DictOfNodes.pickle"

    with open(
        os.path.join(current_script_directory, relative_pathToDictOfNodes), "rb"
    ) as inF:
        dictFile = pickle.load(inF)

    # ---------------------------------------------------
    # ---------------------------------------------------
    # Put the path for DictOfNodes.py file
    # ---------------------------------------------------
    # ---------------------------------------------------

    # ---------------------------------------------------
    # Take input from user for each function pickle file and DictOfNodes.pickle
    # ---------------------------------------------------

    cmdparser = argparse.ArgumentParser()
    cmdparser.add_argument(
        "parent",
        help="Add path for the folder that contains pickle files for each function in two folders Control & Autopilot",
    )
    cmdparser.add_argument("destination")

    args = cmdparser.parse_args()

    parentFolder = args.parent
    destPath = args.destination

    # ---------------------------------------------------
    # Define paths for Control and Autopilot folder
    # ---------------------------------------------------

    ControlFolder = os.path.join(parentFolder, "Control")
    AutoFolder = os.path.join(parentFolder, "Autopilot")

    # ---------------------------------------------------
    # Create links for each file within each subfolder (Control & Autopilot)
    # ---------------------------------------------------

    controlfolderlist = []
    autopilotfolderlist = []

    controlfilelist = []
    autopilotfilelist = []

    for folders in os.listdir(ControlFolder):
        controlfolderlist.append(os.path.join(ControlFolder, folders))

    for eachparentfolder in controlfolderlist:
        for root, dirs, files in os.walk(eachparentfolder):
            for eachfile in os.listdir(root):
                controlfilelist.append(os.path.join(root, eachfile))

    for folders in os.listdir(AutoFolder):
        autopilotfolderlist.append(os.path.join(AutoFolder, folders))

    for eachparentfolder in autopilotfolderlist:
        for root, dirs, files in os.walk(eachparentfolder):
            for eachfile in os.listdir(root):
                autopilotfilelist.append(os.path.join(root, eachfile))

    # ---------------------------------------------------
    # Update and Create a pickle file for each function in Control Folder
    # ---------------------------------------------------

    funcOfControl(controlfilelist, destPath, absolute_pathToEmptyDict, dictFile)

    # ---------------------------------------------------
    # Update and Create a pickle file for each function in Autopilot Folder
    # ---------------------------------------------------

    funcOfAutopilot(autopilotfilelist, destPath, absolute_pathToEmptyDict, dictFile)


if __name__ == "__main__":
    main()
