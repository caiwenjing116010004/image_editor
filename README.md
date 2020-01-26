# Image Editor

## Catalog

- [Image Editor](#image-editor)
  - [Catalog](#catalog)
  - [Introduction](#introduction)
  - [Achievements Descriptions](#achievements-descriptions)
    - [Interface overview](#interface-overview)
    - [Geometric transformations](#geometric-transformations)
    - [Image adjustments](#image-adjustments)
    - [Filters](#filters)
  - [Difficulties and solutions](#difficulties-and-solutions)
    - [Performance problem](#performance-problem)
    - [History problem](#history-problem)

<br>

<br>

## Introduction

This is the course project for CSC3002 (Introduction to Computer Science: Programming Paradigms) . Contributors to this project are:

- 116010004: Wenjing, Cai
- 116010103: Yifan, Lan
- 116010265: Chengwei, Ye



## Achievements Descriptions

### Interface overview

In terms of the graphical user interface, we design two interfaces – the welcome interface and the develop interface. The welcome interface contains an “OPEN” button and a “HELP” button. The develop interface is divided into three parts – the middle part, the top part, and the right part. The image is placed in the middle. On the right part, there is a function plate displaying the basic editing functions as well as the histogram. A tool bar is placed on the top part, containing six buttons for “File”, “Edit”, “Geometry”, “Filter”, “View” and “Help”.



![welcome-interface](C:\Users\Administrator\Documents\GitHub\image_editor\img\welcome-interface.png)

​                                                                                 Welcome interface

The concise welcome interface will show up first upon running the project. A few slices of documentation will be shown if the user clicks the “HELP” button. After clicking the “OPEN” button, the user will be asked to select an image to work on (through a pop-up window).

### Geometric transformations

- Crop;
- Flip;
- Rotate: any degrees / clockwise 90 degrees / counter clockwise 90 degrees;
- Transform: horizontal / vertical.

Functions of Horizontal transform, Vertical transform, and Free rotation appear on the function plate on the right part of the interface, while functions of Rotate right (clockwise 90 degrees), Rotate left (counter clockwise 90 degrees), and Flip appear on the tool bar on the top of the interface. Due to limited space, only the Free rotation function is shown here.



 ![geometric-transformations](C:\Users\Administrator\Documents\GitHub\image_editor\img\geometric-transformations.png)

### Image adjustments

- Color adjustments
  - Class: imgHSB (Hue, Saturation, Brightness)
  - Functions: imgBrightness, whiteBalance, imgWarmth, imgSaturation
- Light adjustments
  - Class: imgSDHL (Shadow, Highlight)
  - Functions: imgContrast, imgShadow, imgHighlight
- Other adjustments
  - Sharpen
  - Blur

In consideration of encapsulation, we implement two classes. The imgHSB class is for color adjustments, with its key instance variables being Hue, Saturation, and Brightness. The imgSDHL class is for light adjustments, with its key instance variables being Shadow and Highlight. We also implement other functions for possible needs, including Sharpening, Blurring, and Border detection. All these functions appear on the function plate on the right part of the interface, with the name of each slider demonstrating its function clearly, which enable beginners to get started without much difficulty. Due to limited space, only the Shadow function is shown here.

![image-adjustments](C:\Users\Administrator\Documents\GitHub\image_editor\img\image-adjustments.png)

 

### Filters

- Thematic: Portrait / Waterscape / Plant / Architecture;
- Artistic: Vintage / Sketch / Black&white / Border detection.

Based on the image processing functions and the imgHSB class introduced above, we design and implement several image filters. All the filters appear on the tool bar on the top of the interface. Due to limited space, only the Vintage filter is shown here.

![Filters](C:\Users\Administrator\Documents\GitHub\image_editor\img\filters.png)





### Histogram

A histogram is placed at the top-right corner of the interface. It displays the brightness of the red channel, the green channel, the blue channel, and the whole channels. Every time the user applies a filter or adjusts the lights or colors, the histogram will change.

![Histogram](C:\Users\Administrator\Documents\GitHub\image_editor\img\histogram.png)





## Difficulties and solutions

There are two major problems that we have encountered when we design the data structure. The first one is the performance problem. The second one is the problem of keeping the history of changes to images.



### Performance problem

If the performance problem is not solved, when the user uses the slider to perform the adjustment, he will encounter serious slowness, which cannot be tolerated. But immediate preview is an important feature of a modern image editor. However, when the user presses buttons, the performance problem is not so serious. Based on this fact, the software generates a smaller image for adjustment. The size of small image is independent of the original image, which means that the size of original image does not affect the performance of the software. When the user finishes a slider adjustment, he has to press a button to confirm that he has finished. Then the software will apply the changes to the original image. The performance problem is solved.

 

### History problem

We want to keep all the history of changes. That means the user can regret and go to the step before the last step. To realize this function, we designed a class called “main_pic”. Its inner structure consists of two vectors containing all the large images and small images. We designed methods that enable the software to store or remove images just like a stack. Because cv::Mat has garbage collection mechanism, we do not worry about the memory storage. Every change we make does not alter the original image. Instead, it generates a new image and puts it in the “main_pic”. It is similar to the idea of “layer”.

With the help of “main_pic”, we enjoy the convenience of keeping every history versions of images, while the overall performance is also guaranteed.