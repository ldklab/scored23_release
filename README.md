# Distinguishing AI and Human-Generated Code: a Case Study

This repository contains the code for the **Distinguishing AI and Human-Generated Code: a Case Study** which is a Code Stylometry tool that parses C/C++ code into an Abstract Syntax Tree, computes n-gram frequencies/counts on the AST, extracts lexical features from the codefiles and uses those as feature vectors for classification tasks using traditional machine learning binary classifiers. 

## Features:

1. Parsing C/C++ code into ASTs
2. Compute N-gram vectors
3. N-gram dictionaries
4. Binary Classification based on Syntactic features
5. Binary Classificaiton based on Lexical features
6. Binary Classification based on Syntactic and Lexical (combined) features

## Prerequisites 
 
1. Download required packages using `pip install -r requirements.txt`
2. Clone and build "TreeSitter" package using the following steps
```bash
cd ASTanalysis
mdkir vendor && cd vendor
git clone https://github.com/tree-sitter/tree-sitter-cpp
cd ..
python builder.py 
# my-languages.so* file will be created under the folder ASTanalysis/build
```
3. Create a new folder "Processed" in the same directory as the "ASTAnalysis" folder.
4. Download and install MongoDB local instance. `docker run -d -p 127.0.0.1:27017:27017 -v <path-to>/db:/data/db mongo:6`
5. Download the ASTAnalysis folder. This contains the code files and the "Dataset" folder. 


## Files: 

#### 1. ASTParser.py
This file parses each C/C++ code files available in the "Dataset" folder in to its Abstract Syntax Trees and saves it in a XML format to a destination folder and in a collection in MongoDB database. 

#### 2. ASTLooper.py
This file executes the ASTParser.py file that loops through the dataset.

#### 3. CreateNodeTypeSet.py
This will create pickle files with all the extracted node types from the ASTs for each code file in the dataset folder. It will also create a text file with all the node types found in all the code files in dataset folder.

#### 4. NGramEmptyPair.py
This file creates the empty dictionaries for bi,tri and quad grams and save them to a pickle file at the desired destination folder.

#### 5. DictOfNodes.py
This file creates a dictionary with the "Key" values as all the node types found within the code and values "Values" of those keys are the generalized node types. You can change the generalized node types from within this file. 

#### 6. BigramDictUpdate.py & TrigramDictUpdate.py & QuadgramDictUpdate.py
This will update the empty dictionary for each code file in source dataset based on the n-gram value (2,3,4). 

#### 7. BigramVectorCreation.py & TrigramVectorCreation.py & QuadgramVectorCreation.py
These files will create the normalized vectors for the each file that was created by the (Bigram/Trigram/Quadgram)DictUpdate.py files. 

#### 8. BiStratClassification.py & TriStratClassification.py & QuadStratClassification.py 
These files will apply the stratified binary classification using RFC, KNN, XGB & SVM on the created normalized vectors for syntactic features.  

#### 9. LexicalLooper.py
This file loops through the source dataset files and executes the LexicalParse.py for each file. 

#### 10. LeixcalParse.py
This file parses the source code file and creates features based on the lexical elements within the file. 

#### 11. LexicalClassification.py
This file will apply the stratified binary classification using RFC, KNN, XGB & SVM on the created normalized vectors for lexical features.  

#### 11. ASTandLexicalLooper.py 
This file loops through the source dataset files and executes the ASTandLexicalParse.py 

#### 12. ASTandLexicalParse.py
This file parses the source code files in the syntactic and lexical features and save those vectors in MongoDB. 

#### 13. ASTandLexicalClassification.py
This file applies the stratified binary classification using RFC, KNN, XGB & SVM on the created normalized vectors for syntactic and lexical features. 



## How To Run: 

#### 1. ASTParser.py 

- Edit the MongoDB database details as per your own setup. The default settings are applied for local default MongoDB database instance.

#### 2. ASTLooper.py

- Run the following command, which will execute the ASTParse.py file 
```bash
python3 ASTLooper.py /absolute/path/to/ASTanalysis/Dataset absolute/path/of/destination/folder
```
- By providing two absolute paths of the below as inputs:

    1. Source dataset folder that has 2 folder (i) Control (ii) Autopilot
    2. Destination folder path that will save the ASTs in XML format. Create a new folder **Graphs** in the **Processed** root directory (see prerquisites)

- This will have 3 outputs:
  1. Creates a database named **CodeStylometry** in MongoDB 
  2. Creates a collection named **Graphs** in the **CodeStylometry** database where AST graphs for each file will be saved.
  3. Saves AST in XML format in the **Graphs** folder created above.

- Follow these steps to double check MongoDB: 
  1. Connect to MongoDB container (if you are using the container set up): `docker ps`
  2. Access the running container using `docker exec -it CONTAINER_NAME_OR_ID bash`. You are currently inside the container, run the following commands to inspect the DB:
     ```bash
     mongosh
     use admin
     show dbs  # you should see the created DB CodeStylometry
     use CodeStylometry
     show collections
     ```

#### 3. CreateNodeTypeSet.py

- Takes a destination folder path as an input argument. Saves the node types in pickle file in the destination folder. Create a new folder **NodeType** in the **Processed** folder (see prerequisites)

- To run the file:

        python3 CreateNodeTypeSet.py /path/to/NodeType

- The following files/folders `Autopilot,buffer.txt,Control,finalNodeTypes.txt` will be created inside the directory **NodeType**

#### 4. NGramEmptyPair.py

- Run the file by providing destination folder path. Create a new folder **EmptyDictionaries** in the **Processed** folder and provide the path to this new folder as input argument. 

- To run the file:

        python3 NGramEmptyPair.py /path/to/EmptyDictionaries

- Outputs 3 empty dictionary files (`dictOfBigram.pickle, dictofQuadgram.pickle, dictofTrigram.pickle`) for each bi, tri and quad combination

#### 5. DictOfNodes.py

- Takes a destination folder path as an input argument. Create the directory **DictOfNodes** inside **Processed**

- To run the file: 

        python3 DictOfNodes.py /path/to/DictOfNodes

- The file `DictOfNodes.pickle` will be created inside the directory **DictOfNodes**

#### 6. BigramDictUpdate.py

- Takes 2 inputs to create a Bigram Dictionary with frequencies of each pair combination in the AST. (i) path to root folder that contains the ASTs created in step # 3 (i.e., **NodeType**) (ii) path to destination folder

- Need to change on line 99 ```pathToEmptyDict``` variable in the code and provide the absolute path to the empty dictionary pickle that was created for bigram ```dictOfBigram.pickle```

- Need to change on line 116 ```DictOfNodes.py``` path in the code. 

- Create a new folder **ASTDictionaries** in the **Processed** folder and give it as an input argument

- To run the file:

        python3 BigramDictUpdate.py /path/to/NodeType /path/to/ASTDictionaries

- This will output folder named **Bigram** containing pickle files with updated frequency for each pair combination

#### 7. TrigramDictUpdate.py

- Repeat the same steps as in step # 6. 

- Provide the path to Trigram Dictionary ```dictOfTrigram.pickle```

- This will output folder named **Trigram** containing pickle files with updated frequency for each pair combination

#### 8. QuadgramDictUpdate.py

- Repeat the same steps as in step # 6. 

- Provide the path to Trigram Dictionary ```dictOfQuadgram.pickle```

- This will output folder named **Trigram** containing pickle files with updated frequency for each pair combination


## Follow Below Steps For Classification Based on Syntactic + Lexical Features After Step # 8:

#### 9. ASTandLexParse.py

- Edit the MongoDB database details as per your own setup. The default settings are applied for local default MongoDB database instance.

#### 10. ASTandLexLooper.py

- This will execute the ASTandLexParse.py file. 

- Run the the file by providing two absolute paths of the below as inputs:

    1. Absolute path to the Dataset folder
    2. Absolute path to AST dictionary folder, either Bigram, Trigram or Quadgram that was created in step # 6, 7 & 8 

- To run the file: 

        python3 ASTandLexLooper.py /absolute/path/of/dataset/folder absolute/path/of/dictionary

- Based on the dictionary input file it will create a new Collection in MongoDB. Collection will be named as ```CombinedVectorWith<Bigram/Trigram/Quadgram>```

- Run the file again for N-gram length 3 and 4

#### 11. ASTandLexClassification.py

- Uncomment the appropriate line from line# 27, 28 or 29 to retrieve the vectors from the required MongoDB collection. 

        # mycol = mydb["CombinedVectorWithBigram"]
        # mycol = mydb["CombinedVectorWithTrigram"]
        # mycol = mydb["CombinedVectorWithQuadgram"]

- To run the file:

        python3 ASTandLexClassification.py


## Follow Below Steps For Classification Based on Syntactic Features Only After Step # 8:

#### 9. BigramVectorCreation.py

- Takes an argument as input to create the normalized vectors for Bigram combination. The path to Bigram source AST folder that was created in step # 6 is the input

- This will output the vector and save in MongoDB under ```ASTBigramVector``` collection

- To run the file:

        python3 BigramVectorCreation.py /path/to/bigram/AST/folder

#### 10. TrigramVectorCreation.py

- Repeat same steps as in step # 9

- Provide the path to Trigram source AST folder

- This will output the vector and save in MongoDB under ```ASTTrigramVector```

#### 11. QuadgramVectorCreation.py

- Repeat same steps as in step # 9

- Provide the path to Quadgram source AST folder

- This will output the vector and save in MongoDB under ```ASTQuadgramVector```

#### 12. BiStratClassification.py

- This will retrieve data from MongoDB Bigram Vector collection and run Classification models on the feature vectors. 

- To run the file:

        python3 BiStratClassification.py

#### 13. TriStratClassification.py

- Does the same as step # 12 but for Trigram Vector collection in MongoDb

To run the file:

        python3 TriStratClassification.py

#### 14. QuadStratClassification.py

- Does the same as step # 12 but for Quadgram Vector collection in MongoDb

To run the file:

        python3 QuadStratClassification.py


## Follow Below Steps For Classification Based on Lexical Features Only (No Need To Run Steps # 1 - 8):

#### 1. LexicalParse.py 

- Edit the MongoDB database details as per your own setup. The default settings are applied for local default MongoDB database instance.

#### 2. LexicalLooper.py

- Run the file providing the source path to the ```Dataset``` folder

- To run the file: 

        python3 LexicalLooper.py /absolute/path/of/dataset/folder 

- This will execute the LexicalParse.py file create a collection named **LexicalVectors** in MongoDB 


#### 3. LexicalStratClassification.py

- This will retrieve data from MongoDB Lexical Vector collection and run Classification models on the feature vectors. 


## External Tools:

1. TreeSitter
2. NetworkX
3. MongoDB
