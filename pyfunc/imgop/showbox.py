from PIL import Image
import Image, ImageDraw
img = Image.open('/Users/c-ten/Desktop/set00_V000_I00002.jpg')
print(img.size)
draw = ImageDraw.Draw(img)
box =  [ (98, 131), (392, 484) ] 
draw.rectangle(box, fill = 128)



del draw
img.show()
