# -*- coding: UTF-8 -*-
from pyjieba import jieba

a = jieba(
        'cppjieba/dict/jieba.dict.utf8',
        'cppjieba/dict/hmm_model.utf8',
        'cppjieba/dict/user.dict.utf8',
        'cppjieba/dict/idf.utf8',
        'cppjieba/dict/stop_words.utf8'
    )

print a

b = a.cut("小明硕士毕业于中国科学院计算所，后在日本京都大学深造")

print "/".join(b)

b = a.cut("小明硕士毕业于中国科学院计算所，后在日本京都大学深造", False)

print "/".join(b)

b = a.cut_all("小明硕士毕业于中国科学院计算所，后在日本京都大学深造")

print "/".join(b)

b = a.cut_for_search("小明硕士毕业于中国科学院计算所，后在日本京都大学深造")

print "/".join(b)

b = a.tag("我是拖拉机学院手扶拖拉机专业的。不用多久，我就会升职加薪，当上CEO，走上人生巅峰。")

for x,y in b.iteritems():
    print x,y

b = a.extract("我是拖拉机学院手扶拖拉机专业的。不用多久，我就会升职加薪，当上CEO，走上人生巅峰。");

for x in b:
    print x['word'], x['weight']