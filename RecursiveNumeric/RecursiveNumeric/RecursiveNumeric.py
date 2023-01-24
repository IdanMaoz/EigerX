import math

def findMaxNumAndCount(maxNum, count):
     num = input("Enter number:")
     if((num[0]=='-' and num[1:].isdigit()) or num.isdigit()):
         num=int(num)
     else:
         return 0,0
     if(num==0):
         return maxNum,count
     if(num>maxNum):
         return findMaxNumAndCount(num,1)
     if(num==maxNum):
         return findMaxNumAndCount(num,count+1)
     else:
         return findMaxNumAndCount(maxNum,count)

if __name__ == '__main__':
    maxNum,count=findMaxNumAndCount(-math.inf,0)
    print("Sequence maximum is:",maxNum,"and we have",count,"of this number in the sequence")
