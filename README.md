# Distinguishing AI and Human-Generated Code: a Case Study

This repository contains the code for the **Distinguishing AI and Human-Generated Code: a Case Studye** which is a Code Stylometry tool that parses C/C++ code into an Abstract Syntax Tree, computes n-gram frequencies/counts on the AST and extracts lexical features and uses those as feature vectors for classification tasks using traditional machine learning binary classifiers. 

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


## How To Run: 

#### 1. ASTParser.py 

- Edit the MongoDB database details as per your own setup. The default settings are applied for local default MongoDB database instance.

#### 2. ASTLooper.py

- Run the the file by providing two absolute paths of the below as inputs:
    1. Source dataset folder that has 2 folder (i) Control (ii) Autopilot
    2. Destination folder path that will save the ASTs in XML format

<br>

- To run the file: 
'python3 <absolute path of source dataset> <absolute path of destination folder>'



## Prerequisites 
 
1. Import "Networkx" package
2. Import "TreeSitter" package
3. 



## External Tools:

1. TreeSitter
2. NetworkX
3. MongoDB
