pyjieba
=======
Pyjieba is a jieba library written in c++ with python bindings.

Requirement
-----------
- python 2.7+

Installation
------------
```sh
$ python setup.py build
$ python setup.py install
```

Getting Started
---------------
```python
>>> from pyjieba import jieba
>>> import json
>>> seg = jieba()
>>> 
>>> seg_list = seg.cut("他来到了网易杭研大厦")
>>> print  "/".join(seg_list)
他/来到/了/网易/杭研/大厦
>>> 
>>> seg_list = seg.cut_all("我来到北京清华大学")
>>> print "/".join(seg_list)
我/来到/北京/清华/清华大学/华大/大学
>>> 
>>> seg_list = seg.cut_for_search("小明硕士毕业于中国科学院计算所，后在日本京都大学深造")
>>> print "/".join(seg_list)
小明/硕士/毕业/于/中国/科学/学院/科学院/中国科学院/计算/计算所/，/后/在/日本/京都/大学/日本京都大学/深造
>>> 
>>> seg_dict = seg.tag("我是拖拉机学院手扶拖拉机专业的。不用多久，我就会升职加薪，当上CEO，走上人生巅峰。")
>>> print ", ".join(["%s:%s"%(x,y) for x,y in seg_dict.items()])
学院:n, 巅峰:n, 走上:v, CEO:eng, 加薪:nr, 升职:v, ，:x, 拖拉机:n, 当上:t, 人生:n, 就:d, 多久:m, 是:v, 专业:n, 不用:v, 会:v, 。:x, 手扶拖拉机:n, 我:r, 的:uj
>>> 
>>> seg_dict = seg.extract("我是拖拉机学院手扶拖拉机专业的。不用多久，我就会升职加薪，当上CEO，走上人生巅峰。")
>>> print json.dumps(seg_dict,ensure_ascii=False)
[{"word": "CEO", "weight": 11.739204307083542}, {"word": "升职", "weight": 10.8561552143}, {"word": "加薪", "weight": 10.642581114}, {"word": "手扶拖拉机", "weight": 10.0088573539}, {"word": "巅峰", "weight": 9.49395840471}, {"word": "拖拉机", "weight": 8.43684584695}, {"word": "当上", "weight": 8.37124856446}, {"word": "多久", "weight": 7.45495783259}, {"word": "走上", "weight": 6.96239316796}, {"word": "人生", "weight": 6.84795660274}, {"word": "学院", "weight": 6.50679936187}, {"word": "专业", "weight": 6.19316545738}, {"word": "不用", "weight": 6.00897299265}]
>>> 
```

License
-------
```
BSD 2-Clause License

Copyright (c) 2017, Quan Zhao <rryqszq@gmail.com>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

```