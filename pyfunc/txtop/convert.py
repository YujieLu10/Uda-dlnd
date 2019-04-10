import re
def main():
    minx = 1000.0
    miny = 1000.0
    maxx = 0.0
    maxy = 0.0
    with open("/Users/c-ten/Desktop/Graduate/003684.txt","r") as f:
        s = f.read()
        s1 = s.split()
        i = 0
        with open("/Users/c-ten/Desktop/Graduate/test.txt","w") as g:
            for si in s1 :
                #with open ...
                #test choose 4 feature's x position
                i = i + 1
                #get positionx
                if i % 30 == 1 or i % 30 == 3 or i % 30 == 5 or i % 30 == 7 or i % 30 == 9 or i % 30 == 11 or i % 30 == 21 or i % 30 == 23:
                    if float(si) < float(minx) and float(si) > float(0):
                        minx = si
                    if float(si) > float(maxx):
                        maxx = si
                #get positiny
                if i % 30 == 2 or i % 30 == 7 or i % 30 == 12 or i % 30 == 17 or i % 30 == 4 or i % 30 == 9 or i % 30 == 14 or i % 30 == 19 :                   
                     if float(si) < float(miny) and float(si) > float(0):
                         miny = si
                     if float(si) > float(maxy):
                         maxy = si
                #another 6 lines
                if i % 24 == 0:
                    w = float(maxx) - float(minx)
                    #save one round
                    w = str(round(w,1))
                    h = float(maxy) - float(miny)
                    h = str(round(h,1))
                    #write to the txt
                    g.write('person' +' '+ str(minx) +' '+str(miny)+' '+w+' '+h+' '+'0 0 0 0 0 0 0\n')
                    minx = 1000.0
                    miny = 1000.0
                    maxx = 0.0
                    maxy = 0.0
 
if __name__ == '__main__':

    main()

