import pymongo
import os
from bson import ObjectId
import networkx as nx
import argparse
import pickle


global nodeSetFinal


nodeSetFinal = set()


def listofids():
    global idlist
    idlist = []

    # ----------------------------------------------------------
    # Query only the ID column
    # ----------------------------------------------------------

    queryallid = mycol.find({}, {"_id": 1})

    # ----------------------------------------------------------
    # Convert column cursor to a list and iterate over each item
    # ----------------------------------------------------------

    listofallid = list(queryallid)

    for ids in listofallid:
        x = ids.get("_id")
        idlist.append(x)



def collectdetails(destFolder):
    for eachrecord in idlist:
        subgraphString = mycol.find_one({"_id": ObjectId(eachrecord)})
        subtree = subgraphString["XML_Graph"]
        parentFolder = subgraphString["Root_Folder"]
        childFolder = subgraphString["Parent_Folder"]
        filename = subgraphString["File_Name"]
        filenameid = eachrecord
        generatelist(subtree, parentFolder, childFolder, filename, destFolder)




def generatelist(subtree, parentFolder, childFolder, filename, destFolder):
    sampleFilePath = os.path.join(destFolder, "buffer.txt")
    text_file = open(sampleFilePath, "w")
    text_file.write(subtree)
    text_file.close()
    G = nx.read_graphml(sampleFilePath)

    nodeTypeList = []

    for node, data in G.nodes(data=True):
        nodeTypeList.append(data)

    nodeList = []

    for nodes in nodeTypeList:
        x = nodes.get("nodeType")
        nodeList.append(x)

    # print(nodeList)

    nodeSet = set((nodeList))

    nodeSetFinal.update(nodeList)

    # print(nodeSet)

    # filename = str(filenameid) + ".txt"

    # # print(filename)
    # pathtofile = os.path.join(sampleFilePath, parentFolder, childFolder)

    # # print(pathtofile)

    # try:
    #     os.makedirs(pathtofile, exist_ok=True)
    #     text_file = open(pathtofile+"/"+filename, "w")
    #     text_file.write(str(nodeList))
    #     text_file.close()
    # except OSError as error:
    #     print("unable to create")

    # ----------------------------------------------------------
    # Create a pickle file for each function file
    # ----------------------------------------------------------

    pathtopickledir = os.path.join(destFolder, parentFolder, childFolder)

    picklefilename = str(filename) + ".pickle"

    try:
        os.makedirs(pathtopickledir, exist_ok=True)
        with open(pathtopickledir + "/" + picklefilename, "wb") as outF:
            pickle.dump(nodeList, outF)
    except OSError as error:
        print("unable to create")


    # ---------------------------------------------------
    # ---------------- MAIN STARTS HERE -----------------
    # ---------------------------------------------------


def main():
    cmdparser = argparse.ArgumentParser()
    cmdparser.add_argument(
        "file", help="Add path for destination folder Node Types set file"
    )

    args = cmdparser.parse_args()
    destFolder = args.file

    # ----------------------------------------------------------
    # Connecting to MongoDB
    # ----------------------------------------------------------

    myclient = pymongo.MongoClient("mongodb://localhost:27017")

    mydb = myclient["CodeStylometry"]

    global mycol

    mycol = mydb["Graphs"]

    # ----------------------------------------------------------
    # Generate list of ids for all the records in the database
    # ----------------------------------------------------------

    listofids()

    # ----------------------------------------------------------
    # Use "idlist" to call each record in mongodb and generate a set of all the node types in all the files
    # ----------------------------------------------------------

    collectdetails(destFolder)

    # ----------------------------------------------------------
    # Use "idlist" to call each record in mongodb and generate a set of all the node types in all the files
    # ----------------------------------------------------------

    sorted(nodeSetFinal)
    nodeSetFinalList = list(nodeSetFinal)
    nodeSetFinalList.sort()

    # ----------------------------------------------------------
    # Saves the final node type list to the destination path
    # ----------------------------------------------------------

    finalFilePath = os.path.join(destFolder, "finalNodeTypes.txt")
    text_file_with_all_nodes = open(finalFilePath, "w")
    text_file_with_all_nodes.write(str(nodeSetFinalList))
    text_file_with_all_nodes.close()


if __name__ == "__main__":
    main()
