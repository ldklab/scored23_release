# ------------------------------------------------------------------------
# This file is to parse each individual file from dataset into trees and save in the mongodb
# ------------------------------------------------------------------------

import os
import networkx as nx
import argparse
from tree_sitter import Language, Parser
import pymongo

# -------------------------------------------------------
# Mongo db initialization commands starts here
# -------------------------------------------------------

myclient = pymongo.MongoClient("mongodb://localhost:27017/")

mydb = myclient["CodeStylometry"]

mycol = mydb["Graphs"]

# -------------------------------------------------------
# Mongo db initialization commands ends here
# -------------------------------------------------------

nodeCount = 0
nodePosition = 0
subtree = []
extractTree = []
newdirectorypath = ""


def printTree(node, parentNode):
    global nodeCount
    nodeCount += 1

    if node.type.strip():
        nodeName = nodeCount
        print(nodeName)
    else:
        nodeName = "separator"
        print(nodeName)

    for child in node.children:
        printTree(child, nodeName)


def convertTree(node, parentNode):
    global nodePosition
    nodePosition += 1

    # if node.type.strip():
    #     nodeName = nodePosition

    # else:
    #     nodeName = "separator"

    nodeName = nodePosition
    if node.type.strip():
        graph.add_node(nodeName, nodeType=node.type)

    else:
        graph.add_node(nodeName, nodeType="separator")

    # graph.add_node(nodeName, nodeType = node.type)

    if not (parentNode is None):
        graph.add_edge(
            parentNode, nodeName, between=str(parentNode) + " - " + str(nodeName)
        )

    for child in node.children:
        convertTree(child, nodeName)



def printnxTree(parentNode):
    childExist = list(nx.neighbors(graph, parentNode))

    if childExist:
        print(parentNode)
        for childnode in childExist:
            # print(childnode)
            printnxTree(childnode)

    else:
        print(parentNode)



def findnxFunctionNodes(graph):
    funcfinder = graph.number_of_nodes()
    type_of_node = nx.get_node_attributes(graph, "nodeType")
    fdefnodeposition = []

    for x in range(1, funcfinder + 1):
        if type_of_node[x] == "function_definition":
            fdefnodeposition.append(x)

    return fdefnodeposition


def extractnxSubTrees(nodelist):
    # for pnode in nodelist:
    # print(nodelist)
    # print(len(nodelist))

    for n in range(0, len(nodelist)):
        extract = extraction(nodelist[n])
        print(extract)
        extractTree.clear()



def extraction(node):
    childExist = list(nx.neighbors(graph, node))
    extractTree.append(node)

    for childNode in childExist:
        if childExist:
            extraction(childNode)

    return extractTree



def savenxSubTrees(nodelist, filepath):
    for pnode in nodelist:
        subtree = nx.DiGraph()
        subtree = nx.dfs_tree(graph, pnode)
        subtreefilename = str(pnode) + "Subtree.xml"
        nx.write_graphml(subtree, filepath + "/" + subtreefilename)



def printwithdfs_tree(
    nodelist, codeByfolder, datafolder, filename, codeBy, destPath, filePath
):
    # # -------------------------------------------------------
    # # Mongo db initialization commands
    # # -------------------------------------------------------

    # myclient = pymongo.MongoClient("mongodb://localhost:27017/")

    # mydb = myclient["localllm"]

    # mycol = mydb["ExpGraphs"]

    # # -------------------------------------------------------
    # # Mongo db initialization commands end here
    # # -------------------------------------------------------

    # -------------------------------------------------------
    # importing elementTree to convert the graph in to string
    # -------------------------------------------------------

    import xml.etree.ElementTree as ET

    # -------------------------------------------------------
    # running for loop for each parent node wherever function definition was identified
    # -------------------------------------------------------

    for parentNode in nodelist:
        subtree = nx.DiGraph()
        subtree = nx.dfs_tree(graph, parentNode)
        subtree = graph.subgraph(subtree).copy()

        # print(subtree)

        # -------------------------------------------------------

        # Create the path for the destination foldername by using splited source foldername
        newdirectorypath = os.path.join(destPath, codeByfolder, datafolder)
        finalpath = os.path.join(newdirectorypath, filename + ".xml")
        try:
            os.makedirs(newdirectorypath, exist_ok=True)
            # Write the graph to new destination folder which will have same folder name as source
            # subtreeName = str(parentNode) + 'subgraph.xml'
            # nx.write_graphml(subtree, newdirectorypath + '/' + subtreeName)
            nx.write_graphml(subtree, finalpath)
        except OSError as error:
            print("unable to create")

        # -------------------------------------------------------
        # Code block to convert the subtree that was created above to a string to save in mongodb
        # -------------------------------------------------------

        # subtreePath = os.path.join(newdirectorypath, subtreeName)

        subtree = ET.parse(finalpath)

        subtree = subtree.getroot()

        str_subtree = ET.tostring(subtree, encoding="unicode")

        # print(str_subtree)

        # -------------------------------------------------------
        # -------------------------------------------------------

        # # -------------------------------------------------------
        # # Code block to convert the parent Graph that was created in previous function to a string to save in mongodb
        # # -------------------------------------------------------

        # parentGraphPath = os.path.join(newdirectorypath, "NetworkGraph.xml")

        # parentGraph = ET.parse(parentGraphPath)

        # parentGraph = parentGraph.getroot()

        # str_parentGraph = ET.tostring(parentGraph, encoding='unicode')

        # # -------------------------------------------------------
        # # -------------------------------------------------------

        # # -------------------------------------------------------
        # # Defining the insert query to insert in mongodb as a record
        # # -------------------------------------------------------

        insertDocument = {
            "File_Name": filename,
            "File_Path": filePath,
            "Coded_By": codeBy,
            "Parent_Folder": datafolder,
            "Root_Folder": codeByfolder,
            "Node_ID": parentNode,
            "Graph_Path": finalpath,
            "XML_Graph": str_subtree,
        }

        # # -------------------------------------------------------
        # # running the insert query in mongodb
        # # -------------------------------------------------------

        x = mycol.insert_one(insertDocument)



def ArrayFunctionName(node, parentNode):
    # global nodeCount
    # nodeCount += 1

    # if node.type.strip()
    #     nodeName = nodeCount
    #     print(nodeName)
    # else:
    #     nodeName = "separator"
    #     print(nodeName)

    # for child in node.children:
    #     printTree(child, nodeName)
    pass

    # ---------------------------------------------------
    # ---------------- MAIN STARTS HERE -----------------
    # ---------------------------------------------------


def main():
    # Parse command line arguments using argparse

    cmdparser = argparse.ArgumentParser()
    cmdparser.add_argument(
        "file", help="Add absolute path to the file that needs to be parsed"
    )
    # cmdparser.add_argument('-parser', help='Add absolute path to Tree Sitter parser library', default='build/my-languages.so')
    cmdparser.add_argument("destfolder")

    args = cmdparser.parse_args()

    # Destination folder given in the looper file
    destPath = args.destfolder

    # get the foldername of the source file so can create the destination foldername of the same name
    splittedPath = args.file.split("/")

    # to remember the filename
    filePath = args.file

    # need foldername to evaluate if code is written by human, machine or human and machine
    if "Control" in filePath:
        codeBy = "Human"

    if "Autopilot" in filePath:
        codeBy = "Machine"

    codeByFolder = splittedPath[-3]
    datafolder = splittedPath[-2]
    filename = os.path.splitext(splittedPath[-1])[0]

    # Load the parser library
    CPP_LANGUAGE = Language("build/my-languages.so", "cpp")
    # PY_LANGUAGE = Language('build/my-languages.so', 'python')
    parser = Parser()
    parser.set_language(CPP_LANGUAGE)

    # Parse the file
    with open(args.file, "rb") as f:
        fcontent = f.read(-1)
        tree = parser.parse(fcontent)

    global graph
    graph = nx.DiGraph()

    global newgraph
    newgraph = nx.DiGraph()

    dfsrootnode = 1

    # print(filePath)
    # print(codeBy)
    # print(datafolder)
    # print(filename)
    # # print(destPath)

    # newdirectorypath = os.path.join(destPath, codeByFolder, datafolder)
    # # print(newdirectorypath)

    # finalpath = os.path.join(newdirectorypath , filename + '.xml')
    # print(finalpath)

    # ------------------------------------------------------------
    # 1. Print every node in the tree (in any order) using a recursive depth-first traversal
    # ------------------------------------------------------------

    # printTree(tree.root_node, None)

    # ------------------------------------------------------------
    # 2. Convert the tree-sitter tree into a networkx graph
    # ------------------------------------------------------------

    convertTree(tree.root_node, None)

    # #Create the path for the destination foldername by using splited source foldername
    # newdirectorypath = os.path.join(destPath, codeByFolder, datafolder)
    # finalpath = os.path.join(newdirectorypath , filename + '.xml')
    # try:
    #     os.makedirs(newdirectorypath, exist_ok=True)
    #     #Write the graph to new destination folder which will have same folder name as source
    #     nx.write_graphml(graph, finalpath)
    # except OSError as error:
    #     print("unable to create")

    # ------------------------------------------------------------
    # 3. Print every node in the networx tree using a recursive depth-first traversal
    # ------------------------------------------------------------

    # printnxTree(dfsrootnode)

    # ------------------------------------------------------------
    # 4. Generate an array which contains every node in the networkx tree which has the string "function_definition" in its name
    # ------------------------------------------------------------

    nxfnodes = findnxFunctionNodes(graph)

    # ------------------------------------------------------------
    # 5. For each node in the array, extract the subtree rooted at that node
    # ------------------------------------------------------------

    # extractnxSubTrees(nxfnodes)

    # ------------------------------------------------------------
    # 6. Save each subtree to a separate file
    # ------------------------------------------------------------

    # savenxSubTrees(nxfnodes, newdirectorypath)

    # ------------------------------------------------------------
    # 7. Create tree with networkx function
    # ------------------------------------------------------------

    printwithdfs_tree(
        nxfnodes, codeByFolder, datafolder, filename, codeBy, destPath, filePath
    )

    # ------------------------------------------------------------
    # 8. Print function name
    # ------------------------------------------------------------


if __name__ == "__main__":
    main()
