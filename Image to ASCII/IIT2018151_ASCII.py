import numpy as np
import skimage
from skimage import io,transform
import cv2
def scale_image(image=np.zeros((100,100)),new_width=100,ascii_block_size=(2,3)):
    original_width, original_height = image.shape
    aspect_ratio = original_height / float(original_width)
    w,h = ascii_block_size
    new_height = int(h/w * aspect_ratio * new_width)
    return skimage.transform.resize(image, (new_width, new_height))


def image2ascii(image=np.zeros((100,100)),new_width=100):
    
    def float2char(x=.1):
        ASCII_CHARS = [ 'W','X','N','^', '&', ':',':',' ','.','.','!','*']
        num_chars = len(ASCII_CHARS)
        return ASCII_CHARS[ int(num_chars*x) ]
    float2char = np.vectorize(float2char)
    image = scale_image(image, new_width=new_width)
    print(image.shape)
    rows = ["".join(row) for row in float2char(.999*image) ]
    return "\n".join(rows)

def handle_image_conversion(imagepath,new_width=100):
    
    image = np.zeros((200,200))
    image = skimage.io.imread( imagepath, as_gray=True)
    image_ascii = image2ascii(image, new_width=new_width)
    print(image_ascii)
    ans = open("Output.txt", "w")
    ans.write(image_ascii)

handle_image_conversion('index.jpeg', new_width=50)