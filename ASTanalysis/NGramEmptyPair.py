import itertools
import os
import argparse
import pickle


# ---------------------------------------------------
# Creating Bigrams
# ---------------------------------------------------


def createBiGram(generalizedNodes):
    pairlist = []

    for eachnode in generalizedNodes:
        for eachinnernode in generalizedNodes:
            pairlist.append(eachnode + "$$" + eachinnernode)

    return pairlist

    # ---------------------------------------------------
    # Creating Bi-Gram Combination Dictionary
    # ---------------------------------------------------


def createBiGramDict(ListOfPair):
    pair_dictionary = dict()

    for eachpair in ListOfPair:
        pair_dictionary.update({eachpair: 0.0})

    return pair_dictionary

    # ---------------------------------------------------
    # Bi-Gram (iii) --- Save Bi-Gram Combination Dictionary in Pickle File
    # ---------------------------------------------------


def BigramInPickle(DictOfBiGram, destFolder):
    finalPath = os.path.join(destFolder, "dictOfBigram.pickle")

    with open(finalPath, "wb") as outF:
        pickle.dump(DictOfBiGram, outF)

    # ---------------------------------------------------
    # Tri-Gram (i) --- Creating Tri-Gram
    # ---------------------------------------------------


def createTriGram(generalizedNodes):
    comb_list = []

    comb_set = itertools.product(generalizedNodes, repeat=3)

    for i in comb_set:
        comb_list.append(i)

    trilist = []

    for eachitem in range(0, (len(comb_list))):
        x = comb_list[eachitem]
        y = "$$".join(x)
        trilist.append(y)

    return trilist

    # ---------------------------------------------------
    # Tri-Gram (ii) --- Creating Tri-Gram Combination Dictionary
    # ---------------------------------------------------


def createTriGramDict(TrigramPair):
    tri_pair_dictionary = dict()

    for eachpair in TrigramPair:
        tri_pair_dictionary.update({eachpair: 0.0})

    return tri_pair_dictionary

    # ---------------------------------------------------
    # Tri-Gram (iii) --- Save Tri-Gram Combination Dictionary in Pickle File
    # ---------------------------------------------------


def TrigramInPickle(DictOfTriGram, destFolder):
    finalPath = os.path.join(destFolder, "dictofTrigram.pickle")

    with open(finalPath, "wb") as outF:
        pickle.dump(DictOfTriGram, outF)


    # ---------------------------------------------------
    # Quad-Gram (i) --- Creating Quad-Gram
    # ---------------------------------------------------


def createQuadGram(generalizedNodes):
    comb_list = []

    comb_set = itertools.product(generalizedNodes, repeat=4)

    for i in comb_set:
        comb_list.append(i)

    quadlist = []

    for eachitem in range(0, (len(comb_list))):
        x = comb_list[eachitem]
        y = "$$".join(x)
        quadlist.append(y)

    return quadlist

    # ---------------------------------------------------
    # Quad-Gram (ii) --- Creating Quad-Gram Combination Dictionary
    # ---------------------------------------------------


def createQuadGramDict(QuadgramPair):
    quad_pair_dictionary = dict()

    for eachpair in QuadgramPair:
        quad_pair_dictionary.update({eachpair: 0.0})

    return quad_pair_dictionary

    # ---------------------------------------------------
    # Quad-Gram (iii) --- Save Quad-Gram Combination Dictionary in Pickle File
    # ---------------------------------------------------


def QuadgramInPickle(DictOfQuadGram, destFolder):
    finalPath = os.path.join(destFolder, "dictofQuadgram.pickle")

    with open(finalPath, "wb") as outF:
        pickle.dump(DictOfQuadGram, outF)


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

    generalizedNodes = set()

    generalizedNodes = {
        "Logical_Operator",
        "Logical_Operator",
        "Quotation",
        "Arithmetic_Operator",
        "Pointer_Reference",
        "Logical_Operator",
        "Quotation",
        "Bracket",
        "Bracket",
        "Arithmetic_Operator",
        "Arithmetic_Operator",
        "Arithmetic_Operator",
        "Arithmetic_Operator",
        "Arithmetic_Operator",
        "Separator",
        "Arithmetic_Operator",
        "Arithmetic_Operator",
        "Arrow_Operator",
        "Dot_Operator",
        "Arithmetic_Operator",
        "Separator",
        "Separator",
        "Relational_Operator",
        "Relational_Operator",
        "Arithmetic_Operator",
        "Relational_Operator",
        "Relational_Operator",
        "Relational_Operator",
        "Logical_Operator",
        "Error",
        "Bracket",
        "Bracket",
        "Declarator",
        "Definition",
        "Declarator",
        "Expression",
        "Expression",
        "Control_Declarator",
        "Control_Statement",
        "Expression",
        "Expression",
        "Definition",
        "Expression",
        "Comment",
        "Statement",
        "Condition",
        "Expression",
        "Constant_Declarator",
        "Control_Declarator",
        "Control_Statement",
        "Declarator",
        "Statement",
        "Expression",
        "Condition_Keyword",
        "Escape_Sequence",
        "Expression_Statement",
        "Declarator",
        "Expression",
        "Identifier",
        "Condition_Keyword",
        "Condition_Statement",
        "Function_Declarator",
        "Function_Definition",
        "Identifier",
        "Condition_Keyword",
        "Condition_Statement",
        "Declarator",
        "Declarator",
        "Definition",
        "Statement",
        "Expression",
        "Logical_Operator",
        "Null",
        "Literal",
        "Input",
        "Input_Parameters",
        "Expression",
        "Pointer_Declarator",
        "Pointer_Expression",
        "Variable_Type_Keyword",
        "Control_Declarator",
        "Control_Statement",
        "Specifier",
        "SizeOf_Operator",
        "Expression",
        "Literal",
        "Constant_Declarator",
        "Specifier",
        "Expression",
        "Definition",
        "Declarator",
        "Declarator",
        "Identifier",
        "Type_Cast",
        "Expression",
        "Variable_Type",
        "Control_Statement",
        "Condition_Keyword",
        "Condition_Statement",
        "Bracket",
        "Logical_Operator",
        "Bracket",
    }

    # # ---------------------------------------------------
    # # Bi-Gram (i) --- Creating Bi-Gram
    # # ---------------------------------------------------

    BigramPair = createBiGram(generalizedNodes)

    # # ---------------------------------------------------
    # # Bi-Gram (ii) --- Creating Bi-Gram Combination Dictionary
    # # ---------------------------------------------------

    DictOfBiGram = createBiGramDict(BigramPair)

    # # ---------------------------------------------------
    # # Bi-Gram (iii) --- Save Bi-Gram Combination Dictionary in Pickle File
    # # ---------------------------------------------------

    BigramInPickle(DictOfBiGram, destFolder)

    # # ---------------------------------------------------
    # # Tri-Gram (i) --- Creating Tri-Gram
    # # ---------------------------------------------------

    TrigramPair = createTriGram(generalizedNodes)

    # # ---------------------------------------------------
    # # Tri-Gram (ii) --- Creating Tri-Gram Combination Dictionary
    # # ---------------------------------------------------

    DictOfTriGram = createTriGramDict(TrigramPair)

    # # ---------------------------------------------------
    # # Tri-Gram (iii) --- Save Tri-Gram Combination Dictionary in Pickle File
    # # ---------------------------------------------------

    TrigramInPickle(DictOfTriGram, destFolder)

    # ---------------------------------------------------
    # Quad-Gram (i) --- Creating Quad-Gram
    # ---------------------------------------------------

    QuadgramPair = createQuadGram(generalizedNodes)

    # ---------------------------------------------------
    # Quad-Gram (ii) --- Creating Quad-Gram Combination Dictionary
    # ---------------------------------------------------

    DictOfQuadGram = createQuadGramDict(QuadgramPair)

    # ---------------------------------------------------
    # Quad-Gram (iii) --- Save Quad-Gram Combination Dictionary in Pickle File
    # ---------------------------------------------------

    QuadgramInPickle(DictOfQuadGram, destFolder)


if __name__ == "__main__":
    main()
