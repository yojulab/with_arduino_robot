from PIL import ImageGrab
import numpy as np
import cv2
while(True):
    img = ImageGrab.grab(bbox=(100,10,400,400)) #bbox specifies specific region (bbox= x,y,width,height)
    img_np = np.array(img)
    frame = cv2.cvtColor(img_np, cv2.COLOR_BGR2GRAY)
    cv2.imshow("test", frame)
    if cv2.waitKey(1) == ord('q'):
        break

cv2.destroyAllWindows()
