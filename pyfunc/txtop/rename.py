# -*- coding: cp936 -*-
import os
path = '/Users/c-ten/Desktop/football_files'

for file in os.listdir(path):

    if os.path.isfile(os.path.join(path,file))==True:

        if file.find('.')<0:

            newname=file+'football_files.jpg'

            os.rename(os.path.join(path,file),os.path.join(path,newname))

