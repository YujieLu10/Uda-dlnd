# -*- coding: cp936 -*-

import os

path = '/Users/c-ten/Desktop/actor_files'

for file in os.listdir(path):

    if os.path.isfile(os.path.join(path,file))==True:
        newname=file + '.jpg'
        os.rename(os.path.join(path,file),os.path.join(path,newname))

#           print file,'ok'
#        print file.split('.')[-1]
