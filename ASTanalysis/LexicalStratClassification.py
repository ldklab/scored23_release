import pymongo
import pandas as pd
import numpy as np
from sklearn.neighbors import KNeighborsClassifier
import xgboost as xgb
from sklearn import svm
from sklearn.model_selection import cross_validate
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import (
    StratifiedKFold,
)


# ---------------------------------------------------
# Create Y array for analysis
# ---------------------------------------------------


def createYarray(CodedBy):
    y_predict = CodedBy.tolist()

    # print(y_predict)
    # print(len(y_predict))
    # print(type(y_predict))

    pandaSeries = pd.Series(y_predict)
    # print(pandaSeries)

    y_PandaSeries = pandaSeries.map({"Human": 0, "Machine": 1})
    # print(y_PandaSeries)

    y = y_PandaSeries.to_numpy()
    # print(y)
    # print(y.shape)

    return y

    # ---------------------------------------------------
    # Create X array for analysis
    # ---------------------------------------------------


def createXarray(OutputVector):
    Xaxis = []

    for item in OutputVector:
        bracketremoved = item[1:-1]
        splittingIntoList = bracketremoved.split(",")
        endList = [float(x) for x in splittingIntoList]
        Xaxis.append(endList)

    Xaxis = np.array(Xaxis)

    X = Xaxis

    return X

    # ---------------------------------------------------
    # Create X array with deleted columns having 0.0 for all records
    # ---------------------------------------------------


def deletedColumns(Xarray):
    summed_Array = np.sum(Xarray, axis=0)

    zeroeth_Index = []

    for count, value in enumerate(summed_Array):
        if value == 0.0:
            zeroeth_Index.append(count)

    delarr = np.delete(Xarray, zeroeth_Index, 1)

    return delarr


def classification(X, y):
    metrics = ["accuracy", "f1", "precision", "recall"]

    stratified_kfold = StratifiedKFold(n_splits=5, shuffle=True, random_state=42)

    knn = KNeighborsClassifier(n_neighbors=5)

    stratknn = cross_validate(knn, X, y, cv=stratified_kfold, scoring=metrics)

    print("*---------------------------Stratified KNN ---------------------------*")
    print(
        "Mean Accuracy for KNN is %0.2f with a Standard Deviation of %0.2f"
        % (stratknn["test_accuracy"].mean(), stratknn["test_accuracy"].std())
    )
    print(
        "Mean F1 Score for KNN is %0.2f with a Standard Deviation of %0.2f"
        % (stratknn["test_f1"].mean(), stratknn["test_f1"].std())
    )
    print(
        "Mean Precision for KNN is %0.2f with a Standard Deviation of %0.2f"
        % (stratknn["test_precision"].mean(), stratknn["test_precision"].std())
    )
    print(
        "Mean Recall for KNN is %0.2f with a Standard Deviation of %0.2f"
        % (stratknn["test_recall"].mean(), stratknn["test_recall"].std())
    )

    # scoreKnn = cross_validate(knn, X, y, scoring = metrics, return_estimator = True)

    # print("*--------------------------- Default KNN ---------------------------*")
    # print('Mean Accuracy for KNN is %0.2f with a Standard Deviation of %0.2f' % (scoreKnn['test_accuracy'].mean(), scoreKnn['test_accuracy'].std()))
    # print('Mean F1 Score for KNN is %0.2f with a Standard Deviation of %0.2f' % (scoreKnn['test_f1'].mean(), scoreKnn['test_f1'].std()))
    # print('Mean Precision for KNN is %0.2f with a Standard Deviation of %0.2f' % (scoreKnn['test_precision'].mean(), scoreKnn['test_precision'].std()))
    # print('Mean Recall for KNN is %0.2f with a Standard Deviation of %0.2f' % (scoreKnn['test_recall'].mean(), scoreKnn['test_recall'].std()))

    print("*---------------------------------------------------------*")

    rfc = RandomForestClassifier(random_state=32)

    stratrfc = cross_validate(rfc, X, y, cv=stratified_kfold, scoring=metrics)

    print("*---------------------------Stratified RFC ---------------------------*")
    print(
        "Mean Accuracy for RFC is %0.2f with a Standard Deviation of %0.2f"
        % (stratrfc["test_accuracy"].mean(), stratrfc["test_accuracy"].std())
    )
    print(
        "Mean F1 Score for RFC is %0.2f with a Standard Deviation of %0.2f"
        % (stratrfc["test_f1"].mean(), stratrfc["test_f1"].std())
    )
    print(
        "Mean Precision for RFC is %0.2f with a Standard Deviation of %0.2f"
        % (stratrfc["test_precision"].mean(), stratrfc["test_precision"].std())
    )
    print(
        "Mean Recall for RFC is %0.2f with a Standard Deviation of %0.2f"
        % (stratrfc["test_recall"].mean(), stratrfc["test_recall"].std())
    )

    # scoreRFC = cross_validate(rfc, X, y, scoring = metrics, return_estimator = True)

    # print("*--------------------------- Default RFC ---------------------------*")

    # print('Mean Accuracy for RFC is %0.2f with a Standard Deviation of %0.2f' % (scoreRFC['test_accuracy'].mean(), scoreRFC['test_accuracy'].std()))
    # print('Mean F1 Score for RFC is %0.2f with a Standard Deviation of %0.2f' % (scoreRFC['test_f1'].mean(), scoreRFC['test_f1'].std()))
    # print('Mean Precision for RFC is %0.2f with a Standard Deviation of %0.2f' % (scoreRFC['test_precision'].mean(), scoreRFC['test_precision'].std()))
    # print('Mean Recall for RFC is %0.2f with a Standard Deviation of %0.2f' % (scoreRFC['test_recall'].mean(), scoreRFC['test_recall'].std()))

    # print("*---------------------------------------------------------*")

    svc = svm.SVC(random_state=23)

    stratsvc = cross_validate(svc, X, y, cv=stratified_kfold, scoring=metrics)

    print("*---------------------------Stratified SVM ---------------------------*")
    print(
        "Mean Accuracy for SVM is %0.2f with a Standard Deviation of %0.2f"
        % (stratsvc["test_accuracy"].mean(), stratsvc["test_accuracy"].std())
    )
    print(
        "Mean F1 Score for SVM is %0.2f with a Standard Deviation of %0.2f"
        % (stratsvc["test_f1"].mean(), stratsvc["test_f1"].std())
    )
    print(
        "Mean Precision for SVM is %0.2f with a Standard Deviation of %0.2f"
        % (stratsvc["test_precision"].mean(), stratsvc["test_precision"].std())
    )
    print(
        "Mean Recall for SVM is %0.2f with a Standard Deviation of %0.2f"
        % (stratsvc["test_recall"].mean(), stratsvc["test_recall"].std())
    )

    # scoreSVM = cross_validate(svc, X, y, scoring = metrics, return_estimator = True)

    # print("*--------------------------- Default SVM ---------------------------*")

    # print('Mean Accuracy for SVM is %0.2f with a Standard Deviation of %0.2f' % (scoreSVM['test_accuracy'].mean(), scoreSVM['test_accuracy'].std()))
    # print('Mean F1 Score for SVM is %0.2f with a Standard Deviation of %0.2f' % (scoreSVM['test_f1'].mean(), scoreSVM['test_f1'].std()))
    # print('Mean Precision for SVM is %0.2f with a Standard Deviation of %0.2f' % (scoreSVM['test_precision'].mean(), scoreSVM['test_precision'].std()))
    # print('Mean Recall for SVM is %0.2f with a Standard Deviation of %0.2f' % (scoreSVM['test_recall'].mean(), scoreSVM['test_recall'].std()))

    # print("*---------------------------------------------------------*")

    xgbModel = xgb.XGBClassifier(random_state=30)

    stratxgb = cross_validate(xgbModel, X, y, cv=stratified_kfold, scoring=metrics)

    print("*--------------------------- Stratified XGB ---------------------------*")
    print(
        "Mean Accuracy for XGB is %0.2f with a Standard Deviation of %0.2f"
        % (stratxgb["test_accuracy"].mean(), stratxgb["test_accuracy"].std())
    )
    print(
        "Mean F1 Score for XGB is %0.2f with a Standard Deviation of %0.2f"
        % (stratxgb["test_f1"].mean(), stratxgb["test_f1"].std())
    )
    print(
        "Mean Precision for XGB is %0.2f with a Standard Deviation of %0.2f"
        % (stratxgb["test_precision"].mean(), stratxgb["test_precision"].std())
    )
    print(
        "Mean Recall for XGB is %0.2f with a Standard Deviation of %0.2f"
        % (stratxgb["test_recall"].mean(), stratxgb["test_recall"].std())
    )

    # scoreXGB = cross_validate(xgbModel, X, y, scoring = metrics, return_estimator = True)

    # print("*---------------------------Default XGB ---------------------------*")

    # print('Mean Accuracy for XGB is %0.2f with a Standard Deviation of %0.2f' % (scoreXGB['test_accuracy'].mean(), scoreXGB['test_accuracy'].std()))
    # print('Mean F1 Score for XGB is %0.2f with a Standard Deviation of %0.2f' % (scoreXGB['test_f1'].mean(), scoreXGB['test_f1'].std()))
    # print('Mean Precision for XGB is %0.2f with a Standard Deviation of %0.2f' % (scoreXGB['test_precision'].mean(), scoreXGB['test_precision'].std()))
    # print('Mean Recall for XGB is %0.2f with a Standard Deviation of %0.2f' % (scoreXGB['test_recall'].mean(), scoreXGB['test_recall'].std()))

    # print("*---------------------------------------------------------*")

    # y_predict_KNN = scoreKnn['estimator'][-1].predict(X_test)

    # print("*---------------------------KNN---------------------------*")

    # KNN_prediction_accuracy_score = accuracy_score(y_test, y_predict_KNN)
    # print("Accuracy : %0.2f" % KNN_prediction_accuracy_score)

    # KNN_prediction_f1_score = f1_score(y_test, y_predict_KNN)
    # print("F1_Score : %0.2f" % KNN_prediction_f1_score)

    # KNN_prediction_precision_score = precision_score(y_test, y_predict_KNN)
    # print("Precision : %0.2f" % KNN_prediction_precision_score)

    # KNN_prediction_recall_score = recall_score(y_test, y_predict_KNN)
    # print("Recall : %0.2f" % KNN_prediction_recall_score)

    # print("*---------------------------RFC---------------------------*")

    # y_predict_RFC = scoreRFC['estimator'][-1].predict(X_test)

    # RFC_prediction_accuracy_score = accuracy_score(y_test, y_predict_RFC)
    # print("Accuracy : %0.2f" % RFC_prediction_accuracy_score)

    # RFC_prediction_f1_score = f1_score(y_test, y_predict_RFC)
    # print("F1_Score : %0.2f" % RFC_prediction_f1_score)

    # RFC_prediction_precision_score = precision_score(y_test, y_predict_RFC)
    # print("Precision : %0.2f" % RFC_prediction_precision_score)

    # RFC_prediction_recall_score = recall_score(y_test, y_predict_RFC)
    # print("Recall : %0.2f" % RFC_prediction_recall_score)

    # print("*---------------------------SVM---------------------------*")

    # y_predict_SVM = scoreSVM['estimator'][-1].predict(X_test)

    # SVM_prediction_accuracy_score = accuracy_score(y_test, y_predict_SVM)
    # print("Accuracy : %0.2f" % SVM_prediction_accuracy_score)

    # SVM_prediction_f1_score = f1_score(y_test, y_predict_SVM)
    # print("F1_Score : %0.2f" % SVM_prediction_f1_score)

    # SVM_prediction_precision_score = precision_score(y_test, y_predict_SVM)
    # print("Precision : %0.2f" % SVM_prediction_precision_score)

    # SVM_prediction_recall_score = recall_score(y_test, y_predict_SVM)
    # print("Recall : %0.2f" % SVM_prediction_recall_score)

    # print("*---------------------------XGB---------------------------*")

    # y_predict_XGB = scoreXGB['estimator'][-1].predict(X_test)

    # XGB_prediction_accuracy_score = accuracy_score(y_test, y_predict_XGB)
    # print("Accuracy : %0.2f" % XGB_prediction_accuracy_score)

    # XGB_prediction_f1_score = f1_score(y_test, y_predict_XGB)
    # print("F1_Score : %0.2f" % XGB_prediction_f1_score)

    # XGB_prediction_precision_score = precision_score(y_test, y_predict_XGB)
    # print("Precision : %0.2f" % XGB_prediction_precision_score)

    # XGB_prediction_recall_score = recall_score(y_test, y_predict_XGB)
    # print("Recall : %0.2f" % XGB_prediction_recall_score)



def main():
    myclient = pymongo.MongoClient("mongodb://localhost:27017/")

    mydb = myclient["CodeStylometry"]

    mycol = mydb["LexicalVectors"]

    from pymongoarrow.monkey import patch_all

    patch_all()

    import numpy as np
    from pymongoarrow.api import Schema

    schema = Schema({"Output_Vector": str, "Coded_By": str})

    npa = mycol.find_numpy_all({}, schema=schema)

    CodedBy = np.array(npa["Coded_By"], dtype=str, copy=True)

    OutputVector = np.array(npa["Output_Vector"], dtype=str, copy=True)

    # ---------------------------------------------------
    # Create Y array for analysis
    # ---------------------------------------------------

    y = createYarray(CodedBy)
    # print(y.shape)

    # ---------------------------------------------------
    # Create X array for analysis
    # ---------------------------------------------------

    Xarray = createXarray(OutputVector)
    # print(Xarray.shape)

    # ---------------------------------------------------
    # Create X array with deleted columns having 0.0 for all records
    # ---------------------------------------------------

    X = deletedColumns(Xarray)
    # print(X.shape)

    # ---------------------------------------------------
    # CClassification of data
    # ---------------------------------------------------

    classification(X, y)


if __name__ == "__main__":
    main()
