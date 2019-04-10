###coding=utf-8
##
###urllib模块提供了读取Web页面数据的接口
##import urllib.request
###re模块主要包含了正则表达式
##import re
###定义一个getHtml()函数
##def getHtml(url):
##    page = urllib.request.urlopen(url)  #urllib.urlopen()方法用于打开一个URL地址
##    html = page.read() #read()方法用于读取URL上的数据
##    return html
##
##def getImg(html):
##    reg = r'src="(.+?\.jpg)" pic_ext'    #正则表达式，得到图片地址
##    imgre = re.compile(reg)     #re.compile() 可以把正则表达式编译成一个正则表达式对象.
##    imglist = re.findall(imgre,html)      #re.findall() 方法读取html 中包含 imgre（正则表达式）的    数据
##    #把筛选的图片地址通过for循环遍历并保存到本地
##    #核心是urllib.urlretrieve()方法,直接将远程数据下载到本地，图片通过x依次递增命名
##    x = 0
##
##    for imgurl in imglist:
##        urllib.request.urlretrieve(imgurl,'/Users/c-ten/Desktop/worm/%s.jpg' % x)
##        x+=1
##
##
##html = getHtml("http://image.baidu.com/search/index?tn=baiduimage&ct=201326592&lm=-1&cl=2&ie=gbk&word=masked%20faces&hs=2&xthttps=000000&fr=ala&ori_query=masked%20faces&ala=0&alatpl=sp&pos=0")
###print getImg(html)
#<span style="color:#330099;">'''
#Created on 2017-4-17

#@author: Administrator
#'''
import urllib.request
import re

def gethtml(url):
    html=urllib.request.urlopen(url)
    data=html.read()
    return data.decode("utf-8")
def getimg(html):
    dir="/Users/c-ten/Desktop/worm/"  #图片保存路径
    reg='src="(.+?\.jpg)" pic_ext' 
    imgreg=re.compile(reg)
    imglist=imgreg.findall(html)
    x=0
    for i in imglist:
        print(i)
        urllib.request.urlretrieve(i,'{}{}.jpg'.format(dir, x))
        x=x+1

print('gethtml')
html=gethtml("http://image.baidu.com/search/index?tn=baiduimage&ct=201326592&lm=-1&cl=2&ie=gbk&word=%BF%DA%D5%D6%C3%B1%D7%D3%D5%DA%B5%B2%C8%CB%C1%B3%CD%BC%C6%AC&hs=2&xthttps=000000&fr=ala&ori_query=%E5%8F%A3%E7%BD%A9%E5%B8%BD%E5%AD%90%E9%81%AE%E6%8C%A1%E4%BA%BA%E8%84%B8%E5%9B%BE%E7%89%87&ala=0&alatpl=sp&pos=0")
print('getimg')
getimg(html)
#</span><span style="color:#333333;">
#</span>
