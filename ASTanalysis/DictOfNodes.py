import os
import pickle
import argparse


def createDictionary(destFolder):
    dictionaryOfNodes = {
        "!": "Logical_Operator",
        "!=": "Logical_Operator",
        '"': "Quotation",
        "%": "Arithmetic_Operator",
        "&": "Pointer_Reference",
        "&&": "Logical_Operator",
        "'": "Quotation",
        "(": "Bracket",
        ")": "Bracket",
        "*": "Arithmetic_Operator",
        "*=": "Arithmetic_Operator",
        "+": "Arithmetic_Operator",
        "++": "Arithmetic_Operator",
        "+=": "Arithmetic_Operator",
        ",": "Separator",
        "-": "Arithmetic_Operator",
        "--": "Arithmetic_Operator",
        "->": "Arrow_Operator",
        ".": "Dot_Operator",
        "/": "Arithmetic_Operator",
        ":": "Separator",
        ";": "Separator",
        "<": "Relational_Operator",
        "<=": "Relational_Operator",
        "=": "Arithmetic_Operator",
        "==": "Relational_Operator",
        ">": "Relational_Operator",
        ">=": "Relational_Operator",
        "?": "Logical_Operator",
        "ERROR": "Error",
        "[": "Bracket",
        "]": "Bracket",
        "abstract_pointer_declarator": "Declarator",
        "argument_list": "Definition",
        "array_declarator": "Declarator",
        "assignment_expression": "Expression",
        "binary_expression": "Expression",
        "break": "Control_Declarator",
        "break_statement": "Control_Statement",
        "call_expression": "Expression",
        "cast_expression": "Expression",
        "char_literal": "Definition",
        "comma_expression": "Expression",
        "comment": "Comment",
        "compound_statement": "Statement",
        "condition_clause": "Condition",
        "conditional_expression": "Expression",
        "const": "Constant_Declarator",
        "continue": "Control_Declarator",
        "continue_statement": "Control_Statement",
        "declaration": "Declarator",
        "delete": "Statement",
        "delete_expression": "Expression",
        "else": "Condition_Keyword",
        "escape_sequence": "Escape_Sequence",
        "expression_statement": "Expression_Statement",
        "field_designator": "Declarator",
        "field_expression": "Expression",
        "field_identifier": "Identifier",
        "for": "Condition_Keyword",
        "for_statement": "Condition_Statement",
        "function_declarator": "Function_Declarator",
        "function_definition": "Function_Definition",
        "identifier": "Identifier",
        "if": "Condition_Keyword",
        "if_statement": "Condition_Statement",
        "init_declarator": "Declarator",
        "initializer_list": "Declarator",
        "initializer_pair": "Definition",
        "new": "Statement",
        "new_expression": "Expression",
        "not": "Logical_Operator",
        "null": "Null",
        "number_literal": "Literal",
        "parameter_declaration": "Input",
        "parameter_list": "Input_Parameters",
        "parenthesized_expression": "Expression",
        "pointer_declarator": "Pointer_Declarator",
        "pointer_expression": "Pointer_Expression",
        "primitive_type": "Variable_Type_Keyword",
        "return": "Control_Declarator",
        "return_statement": "Control_Statement",
        "sized_type_specifier": "Specifier",
        "sizeof": "SizeOf_Operator",
        "sizeof_expression": "Expression",
        "string_literal": "Literal",
        "struct": "Constant_Declarator",
        "struct_specifier": "Specifier",
        "subscript_expression": "Expression",
        "template_argument_list": "Definition",
        "template_function": "Declarator",
        "type_descriptor": "Declarator",
        "type_identifier": "Identifier",
        "type_qualifier": "Type_Cast",
        "unary_expression": "Expression",
        "unsigned": "Variable_Type",
        "update_expression": "Control_Statement",
        "while": "Condition_Keyword",
        "while_statement": "Condition_Statement",
        "{": "Bracket",
        "||": "Logical_Operator",
        "}": "Bracket",
        "NULL":"Null",
        "character":"Constant_Declarator",
        "else_clause":"Condition",
        "string_content":"Statement",
        "subscript_argument_list":"Definition"
    }

    dictPath = os.path.join(destFolder, "DictOfNodes.pickle")

    try:
        os.makedirs(destFolder, exist_ok=True)
        with open(dictPath, "wb") as outF:
            pickle.dump(dictionaryOfNodes, outF)
    except OSError as error:
        print("unable to create")


def main():
    cmdparser = argparse.ArgumentParser()
    cmdparser.add_argument(
        "file", help="Add path for destination folder Node Types set file"
    )

    args = cmdparser.parse_args()
    destFolder = args.file

    createDictionary(destFolder)


if __name__ == "__main__":
    main()
