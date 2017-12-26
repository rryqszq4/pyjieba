# -*- coding: UTF-8 -*-
import pyjieba

a = pyjieba.pyjieba(
        'cppjieba/dict/jieba.dict.utf8',
        'cppjieba/dict/hmm_model.utf8',
        'cppjieba/dict/user.dict.utf8',
        'cppjieba/dict/idf.utf8',
        'cppjieba/dict/stop_words.utf8'
    )

print a

b = a.cut("小明硕士毕业于中国科学院计算所，后在日本京都大学深造");

print b

b = a.cut_all("小明硕士毕业于中国科学院计算所，后在日本京都大学深造");

print b

b = a.cut_for_search("小明硕士毕业于中国科学院计算所，后在日本京都大学深造");

print b