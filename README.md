# Distinguishing AI and Human-Generated Code: a Case Study

This repository contains the code for the **Distinguishing AI and Human-Generated Code: a Case Study** which is a Code Stylometry tool that parses C/C++ code into an Abstract Syntax Tree, computes n-gram frequencies/counts on the AST, extracts lexical features from the codefiles and uses those as feature vectors for classification tasks using traditional machine learning binary classifiers. 

## Features:

1. Parsing C/C++ code into ASTs
2. Compute N-gram vectors
3. Dictionary
4. 

## Files: 

#### 1. ASTParser.py
This file parses each C/C++ code files available in the "Dataset" folder in to its Abstract Syntax Trees and saves it in a XML format to a destination folder and in a collection in MongoDB database. 

#### 2. ASTLooper.py
This file executes the ASTParser.py file that loops through the dataset.

#### 3. CreateNodeTypeSet.py
This will create pickle files with all the extracted node types from the ASTs for each code file in the dataset folder. It will also create a text file with all the node types found in all the code files in dataset folder.

#### 4. NGramEmptyPair.py
This file creates the empty dictionaries for bi,tri and quad grams and save them to a pickle file at the desired destination folder.

## How To Run: 

#### 1. ASTParser.py 

- Edit the MongoDB database details as per your own setup. The default settings are applied for local default MongoDB database instance.

#### 2. ASTLooper.py

- Run the the file by providing two absolute paths of the below as inputs:

    1. Source dataset folder that has 2 folder (i) Control (ii) Autopilot
    2. Destination folder path that will save the ASTs in XML format. Create a new folder **Graphs** in the **Processed** root directory (see prerquisites)

- To run the file: 

        python3 ASTLooper.py /absolute/path/of/dataset/folder absolute/path/of/destination/folder

- This will have 3 outputs:

    1. Creates a database named **CodeStylometry** in MongoDB 
    2. Creates a collection named **Graphs** in the **CodeStylometry** database with AST graphs for each file will be saved
    3. Saves AST in XML format in the **Graphs** folder created above

#### 3. CreateNodeTypeSet.py

- Takes a destination folder path as an input argument. Saves the node types in pickle file in the destination folder. Create a new folder **NodeType** in the **Processed** folder (see prerequisites)

- To run the file:

        python3 CreateNodeTypeSet.py /destination/folder/path

#### 4. NGramEmptyPair.py

- Run the file by providing destination folder path. Create a new folder **EmptyDictionaries** in the **Processed** folder and provide the path to this new folder as input argument. 

- To run the file:

        python3 NGramEmptyPair.py /path/to/destination/folder





## Prerequisites 
 
1. Download and install "Networkx" package
2. Download and install "TreeSitter" package
3. Create a new folder "Processed" in the same directory as the "ASTAnalysis" folder. 



## External Tools:

1. TreeSitter
2. NetworkX
3. MongoDB
