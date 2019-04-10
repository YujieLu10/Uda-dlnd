from PIL import Image
import os
import re
def main():
    minx = 1000
    miny = 1000
    maxx = 0
    maxy = 0
    per_w = 1.0 #new_w/old_w = new_x/old_x
    per_h = 1.0
    path = '/Users/c-ten/Desktop/okay/newset'
    with open("/Users/c-ten/Desktop/imglist.txt","r") as e:
        for file in os.listdir(path):
            if os.path.isfile(os.path.join(path,file))==True:
                temp = file
                if temp == '.DS_Store':
                    continue

                print(temp)
                with open("/Users/c-ten/Desktop/okay/newset/"+temp,"r") as f:
                    s = f.read()
                    s1 = []
                    s1 = s.split()
                    #print(s1)
                    line = str(e.readline().strip())
                    line = line[0:17] + '.txt'
                    i = 0
                    #---resize the image---
                    img = Image.open('/Users/c-ten/Desktop/okay/bigdataimages2/'+temp[0:6]+'.jpg')
                    print(img.size)
                    per_w = float(640.0/float(img.size[0]))
                    per_h = float(480.0/float(img.size[1]))
                    img = img.resize((640,480),Image.BILINEAR)
                    img.save("/Users/c-ten/Desktop/okay/tran_img/"+line[0:17]+".jpg")
                    #----------------------
                    with open("/Users/c-ten/Desktop/okay/tran_anno/"+line,"w") as g:
                        print(line)
                        for si in s1 :
                            #with open ...
                            #test choose 4 feature's x position
                            i = i + 1
            #                print('debug')
                            if i % 24 == 1 or i % 24 == 3 or i % 24 == 5 or i % 24 == 7 or i % 24 == 9 or i % 24 == 11 or i % 24 == 21 or i % 24 == 23:
#                                print(si)
                                if float(si) < float(minx) and float(si) > float(0):
                                    minx = float(si)
                                if float(si) > float(maxx):
                                    maxx = float(si)
                            
                            if i % 24 == 2 or i % 24 == 7 or i % 24 == 12 or i % 24 == 17 or i % 24 == 4 or i % 24 == 9 or i % 24 == 14 or i % 24 == 19 :                   
            #                    print(si)
                                 if float(si) < float(miny) and float(si) > float(0):
                                     miny = float(si)
                                 if float(si) > float(maxy):
                                     maxy = float(si)
                            if i % 24 == 0:
                                w = (float(maxx) - float(minx))*per_w
                                w = str(int(w))

                                h = (float(maxy) - float(miny))*per_h
                                h = str(int(h))
                                minx = int(minx * per_w)
                                miny = int(miny * per_h)
                
                                g.write('person' +' '+ str(minx) +' '+str(miny)+' '+w+' '+h+' '+'0 0 0 0 0 0 0\n')
                                minx = 1000.0
                                miny = 1000.0
                                maxx = 0.0
                                maxy = 0.0
            #                person = "person" + (str)(minx) + (str)(miny) + (str)(maxx - minx) + (str)(maxy - miny) + '0' + '0' + '0' + '0' + '0' + '0' + '0'
            #                g.write(person)
                        g.close()
                    f.close()
 
if __name__ == '__main__':

    main()

