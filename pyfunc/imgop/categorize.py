import os
import re
def main():
    flag = 1
    path = '/Users/c-ten/Desktop/bigdataimages'
    with open("/Users/c-ten/Desktop/newsetlist.txt","r") as e:
        line = str(e.readline().strip())
        for file in os.listdir(path):
            if os.path.isfile(os.path.join(path,file))==True:
                temp = file
                if temp == '.DS_Store':
                    continue
                if line[0:6] != temp[0:6]:
                    line = line[0:6] + '.png'
                    os.rename(os.path.join(path,file),os.path.join(path,line))
                    flag = 0
                else:
                    flag = 1
                if flag:
                    line = str(e.readline().strip())
                    continue
    e.close()
 
if __name__ == '__main__':

    main()

