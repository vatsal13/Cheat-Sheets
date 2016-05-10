===========
Type Cast :
===========

>>> a = (1,)
>>> type(a)==tuple
True

>>> type({})
<type 'dict'>

>>> type('asdas')
<type 'str'>

>>> type([])
<type 'list'>



===========
Try catch :
===========

try :
	pass
except Exception, e :
	pass



======================
Capitalize and Lower :
======================

>>> 'a'.capitalize()
'A'
>>> str.capitalize('a')
'A'
>>> 'a'.lower()
'a'
>>> str.lower('A')
'a'



====================================
Check is object belongs to a class :
====================================

>>> class A:
...     pass
... 

>>> o = A()

>>> type(o)
<type 'instance'>

>>> isinstance(o,A)
True



=======
Power :
=======

>>> 2 ** (1/2.)
1.4142135623730951

>>> 2 ** (1/float(2))
1.4142135623730951

>>> 2 ** 3
8

# pow(a,b) % mod
>>> pow(a,b,m) # more efficiently

>>> (11**34) % 6
1L #long but answer is 1 for both

>>> pow(11,34,6)
1 #int, hence more efficient



========================================
Enumerate over keys and values in dict :
========================================

>>> d = {'a':23, 'b': 3, 'z': 7}

>>> for k, v in d.iteritems():
...     print k,v
... 
a 23
b 3
z 7



========================================
Enumerate over index and values in list :
========================================

>>> l = ['s', 2, 2.5, 147]

>>> for i, v in enumerate(l):
...     print i, v
... 
0 s
1 2
2 2.5
3 147



=========================
range(start, end, step) :
=========================

>>> range(0,12)
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]

>>> range(0,12,3)
[0, 3, 6, 9]

>>> range(0,12,5)
[0, 5, 10]

>>> reversed(range(0,12))
<listreverseiterator object at 0x7fb2bd1a8a10>

>>> for i in reversed(range(0,12)):
...     print i,
... 
11 10 9 8 7 6 5 4 3 2 1 0



===========
Round off :
===========

>>> round(0.579)
1.0

>>> round(0.579 ,2)
0.58

>>> round(0.579 ,1)
0.6

>>> print "%.2f"% 0.579
0.58

>>> print "%.2f"% 0.6
0.60

>>> print "%.2f"% round(0.579,1)
0.60



==========================================
List count and index and sum and reverse :
==========================================

>>> l  = [1,2,3,4,5,6,7,7,7,5]
>>> l
[1, 2, 3, 4, 5, 6, 7, 7, 7, 5]
>>> l.index(7)
6
>>> l.index(5)
4
>>> l.count(5)
2
>>> l.count(7)
3
>>> sum(l)
47


>>> l  = [1,2,3,4,5,6,7]
>>> l.reverse()
>>> l
[7, 6, 5, 4, 3, 2, 1]




===========================
Ascii value :
===========================

>>> ord('a')
97
>>> chr(97)
'a'
>>> ord('A')
65
>>> 97-65
32
>>> ord('A')+32
97
>>> chr(ord('A')+32)
'a'



=======
Stack :
=======

>>> l
[1, 2, 3, 4, 5, 6, 7, 7, 7, 5]

>>> l.pop()
5
>>> l.pop()
7

>>> l
[1, 2, 3, 4, 5, 6, 7, 7]

>>> l.append(199)
>>> l.append(200)

>>> l
[1, 2, 3, 4, 5, 6, 7, 7, 199, 200]



=============================
Doubly-linked-list or queue :
=============================

>>> from collections import deque

>>> q = deque()

>>> q.append(1)
>>> q.append(2)
>>> q.append(5)
>>> q.append(6)
>>> q
deque([1, 2, 5, 6])


>>> q.pop()
6
>>> q
deque([1, 2, 5])


>>> q.popleft()
1
>>> q
deque([2, 5])


>>> q.appendleft(191)
>>> q
deque([191, 2, 5])


>>> q.append(299)
>>> q
deque([191, 2, 5, 299])



===========
Deep Copy :
===========

>>> from copy import deepcopy

>>> l1 = deepcopy(l2)
>>> l1
['a', 'b', [1, 'ba']]
>>> l2[2][0]=3
>>> l2
['a', 'b', [3, 'ba']]
>>> l1
['a', 'b', [1, 'ba']]

# shallow copy - does not work if inner lists or dicts exits
# >>> lst1 = ['a','b',['ab','ba']]
# >>> l2 = list(lst1)
# >>> l2
# ['a', 'b', ['ab', 'ba']]
# >>> l2[2][0]=1
# >>> l2
# ['a', 'b', [1, 'ba']]
# >>> lst1
# ['a', 'b', [1, 'ba']]



================
PriorityQueue : 
================

class PQ:
	def __init__(self, val):
		self.val = val
	def __cmp__(self, other):
		return cmp(other.val,self.val)

import Queue

q = Queue.PriorityQueue()
q.put(PQ(1))
q.put(PQ(2))
q.put(PQ(3))
print q.get().val



=================
Misc :
=================
def j(a):
...     return -1*a
... 
>>> a.sort(key=j)
>>> a
[6, 5, 4, 3, 2, 2, 1]


>>> sorted(a,key=j)
[6, 5, 4, 3, 2, 2, 1]

