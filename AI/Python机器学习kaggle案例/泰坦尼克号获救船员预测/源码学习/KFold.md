# K-Folds cross-validator  K折交叉验证

Provides train/test indices to split data in train/test sets. 
提供训练/测试索引以将数据拆分为训练/测试集。

Split dataset into k consecutive folds (without shuffling by default).
将数据集拆分为k个连续的折叠（默认情况下不进行混洗）。

Each fold is then used once as a validation while the k - 1 remaining folds form the training set.
然后将每个折叠用作一次验证，而剩余k-1个折叠形成训练集。

Read more in the :ref:`User Guide <cross_validation>`.
在用户指南<cross_validation>中阅读更多内容。

## Parameters 参量
----------
n_splits : int, default=3
n_splits：int，默认= 3

Number of folds. Must be at least 2.
折数。 必须至少为2。

.. versionchanged:: 0.20
版本已更改：： 0.20

``n_splits`` default value will change from 3 to 5 in v0.22.
在v0.22中，``n_splits''的默认值将从3更改为5。

shuffle : boolean, optional 
随机播放：布尔值，可选

Whether to shuffle the data before splitting into batches.
在拆分成批次之前是否对数据进行混洗。

random_state : int, RandomState instance or None, optional, default=None
random_state：int，RandomState实例或无，可选，默认=无

If int, random_state is the seed used by the random number generator;
如果为int，则random_state是随机数生成器使用的种子；否则为false。

If RandomState instance, random_state is the random number generator;
如果是RandomState实例，则random_state是随机数生成器；

If None, the random number generator is the RandomState instance used by `np.random`. 
如果为None，则随机数生成器是np.random使用的RandomState实例。

Used when ``shuffle`` == True.
在``shuffle''== True时使用。

## Examples    例子
--------
>>> import numpy as np
>>> from sklearn.model_selection import KFold
>>> X = np.array([[1, 2], [3, 4], [1, 2], [3, 4]])
>>> y = np.array([1, 2, 3, 4])
>>> kf = KFold(n_splits=2)
>>> kf.get_n_splits(X)
2
>>> print(kf)  # doctest: +NORMALIZE_WHITESPACE
KFold(n_splits=2, random_state=None, shuffle=False)
>>> for train_index, test_index in kf.split(X):
    ...    print("TRAIN:", train_index, "TEST:", test_index)
    ...    X_train, X_test = X[train_index], X[test_index]
    ...    y_train, y_test = y[train_index], y[test_index]
TRAIN: [2 3] TEST: [0 1]
TRAIN: [0 1] TEST: [2 3]

## Notes  笔记
-----
The first ``n_samples % n_splits`` folds have size ``n_samples // n_splits + 1``, other folds have size ``n_samples // n_splits``, where ``n_samples`` is the number of samples.
第一个``n_samples％n_splits''个折叠的大小为``n_samples // n_splits + 1''，其他折叠的大小为``n_samples // n_splits''，其中``n_samples''是样本数。


Randomized CV splitters may return different results for each call of split. 
随机CV分割器可能会为每个分割调用返回不同的结果。

You can make the results identical by setting ``random_state`` to an integer.
您可以通过将random_state设置为整数来使结果相同。

## See also    也可以看看
--------
StratifiedKFold
分层KFold

Takes group information into account to avoid building folds with imbalanced class distributions (for binary or multiclass classification tasks).
考虑组信息，以避免因类分布不均衡而导致折叠（对于二进制或多类分类任务）。

GroupKFold: K-fold iterator variant with non-overlapping groups.
GroupKFold：具有非重叠组的K折迭代器变体。

RepeatedKFold: Repeats K-Fold n times.
RepeatedKFold：重复N次折叠。
    
    
## Code

```
class KFold(_BaseKFold):
    def __init__(self, n_splits='warn', shuffle=False,random_state=None):
        if n_splits == 'warn':
            warnings.warn(NSPLIT_WARNING, FutureWarning)
            n_splits = 3
        super().__init__(n_splits, shuffle, random_state)

    def _iter_test_indices(self, X, y=None, groups=None):
        n_samples = _num_samples(X)
        indices = np.arange(n_samples)
        if self.shuffle:
            check_random_state(self.random_state).shuffle(indices)

        n_splits = self.n_splits
        fold_sizes = np.full(n_splits, n_samples // n_splits, dtype=np.int)
        fold_sizes[:n_samples % n_splits] += 1
        current = 0
        for fold_size in fold_sizes:
            start, stop = current, current + fold_size
            yield indices[start:stop]
            current = stop

```
