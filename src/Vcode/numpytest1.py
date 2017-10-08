import numpy as np
import cv2
from PIL import Image


def get_operator(operator_path, expand=False):
    shape_gray = cv2.imread(operator_path, 0)

    _, shape_binary = cv2.threshold(shape_gray, 127, 255, cv2.THRESH_BINARY)

    contours, hierarchy = cv2.findContours(shape_binary, cv2.RETR_TREE, cv2.CHAIN_APPROX_NONE)
    # print(cv2.findContours(shape_binary, cv2.RETR_TREE, cv2.CHAIN_APPROX_NONE))
    contour = contours[0]

    operator = np.zeros((133, 133))

    for point in contour:
        operator[point[0][0]][point[0][1]] = 1
        if expand:
            if point[0][0] > 0:
                operator[point[0][0] - 1][point[0][1]] = 1
            if point[0][0] < 132:
                operator[point[0][0] + 1][point[0][1]] = 1
            if point[0][1] > 0:
                operator[point[0][0]][point[0][1] - 1] = 1
            if point[0][1] < 132:
                operator[point[0][0]][point[0][1] + 1] = 1

    return operator


def predict(img_path, op_path):
    img_gray = cv2.imread(img_path, 0)
    img_canny = cv2.Canny(img_gray, 100, 200)
    # op_gray = cv2.imread(op_path, 0)
    # op_canny = cv2.Canny(op_gray, 100, 200)
    op_canny = get_operator(op_path)
    height, width = img_canny.shape
    opheight, opwidth = op_canny.shape

    m = 0
    x = 0
    y = 0
    for i in range(0, height - opheight):
        for j in range(0, width - opwidth):

            part = img_canny[(i):(i + opheight), (j):(j + opwidth)]
            #if (i == 15 and j == 199):
            #   print "break"
                # cv2.imwrite("15_199.png", part)
            # print(part.shape)
            # diff = abs(part - op_canny).sum()
            diff = (part * op_canny).sum()

            if (diff > m):
                m = diff
                x = j
                y = i
    #print x
    return x
    # cv2.imwrite("desktop_canny.png", img_canny)
    # cv2.imwrite("op_canny.png", op_canny)
    # cv2.imwrite("part.png", img_canny[y:y + opheight, x:x + opwidth])


if __name__ == "__main__":
    print predict("desktopmix.png", "shape.png")
