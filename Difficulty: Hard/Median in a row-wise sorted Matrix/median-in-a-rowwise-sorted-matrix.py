class Solution:
    def median(self, mat):
    	# code here
    	l=[]
    	for i in mat:
    	    l+=i
    	l.sort()
    	return l[len(l)//2]
    	