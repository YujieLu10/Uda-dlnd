from PIL import Image
img = Image.open('/Users/c-ten/Desktop/tmp/set00_V010_I01052.jpg')
print(img.size)
new_img = img.resize((640,480),Image.BILINEAR)
new_img.save("/Users/c-ten/Desktop/tmp/set00_V010_I01052.jpg")
