<h1>GarageVision</h1>

<p>An AI approach to a computer vision system.</p> 

<h2 style="color:orange;">ChatGTP Prompt<a id=chatGTP_prompt></a></h2>

**How to create a vision system that can recognize motorcycle parts in 3d using a camera in 4 corners of a room.**

<h2> <font color=#339966>
    ChatGTP Response <a id=chatGTP-response></a>
</font></h2>

Creating a vision system that can recognize motorcycle parts in 3D using cameras in four corners of a room is a complex task that would involve several steps. Here is a high-level overview of some of the key steps involved:

1. [Calibrate the cameras:](#header--1) The first step is to calibrate the cameras to make sure that they are all accurately capturing the same view of the room. This can be done using techniques like camera calibration and stereo calibration.

2. [Collect training data:](#header--2) Collect training data by capturing images of motorcycle parts in different orientations and locations in the room. This data will be used to train a machine learning model to recognize the parts.

3. [Pre-processing:](#header--3) Pre-process the images by performing tasks such as cropping, resizing, and normalizing the images.

4. [Build the model:](#header--4) Use the collected training data to train a machine learning model that can recognize the motorcycle parts. This can be done using techniques such as convolutional neural networks or deep learning algorithms.

5. [Implement the system:](#header--5) Once the model is trained, it needs to be integrated into the vision system. This includes installing the cameras, configuring the software, and setting up the system to process the images and recognize the parts in real-time.

6. [Test and refine the system:](#header--6) Test the system by introducing parts in different orientations and locations in the room and fine-tune the parameters and algorithms until the system performs correctly.

*Please note that this is a high-level overview and there are many complex details and nuances involved in each step. It would require a good amount of knowledge in Computer Vision, Machine Learning, and Robotics. Additionally, it would be best to consult with experts in the field if you plan to develop this system.*

## 1: Calibrate the cameras<a id="header--1"></a>

### ChatGTP Prompt

**How can I calibrate 4 ESP-32 Cameras for a vision system**

### ChatGTP Response

Calibrating multiple cameras for a vision system can be a complex task, but there are a few steps that you can take to make the process easier. Here is a general overview of how to calibrate four ESP-32 cameras for a vision system:

1. [Capture calibration images:](#header--1-1) The first step is to capture calibration images using all four cameras. This can be done by positioning the cameras in the desired locations, and then capturing images of a calibration pattern (such as a checkerboard) from different angles.

2. [Extract camera parameters:](#header--1-2) Next, you will need to extract the camera parameters for each camera. This can be done using software such as OpenCV's camera calibration functions. These functions will analyze the calibration images and calculate the intrinsic and extrinsic parameters for each camera.

3. [Synchronize the cameras:](#header--1-3) Synchronize the cameras so that the images captured by each camera are time-stamped and can be correlated with images from other cameras. This can be done by connecting the cameras to a common trigger or by using software-based synchronization.

4. [Stereo Calibration:](#header--1-4) Once the cameras are calibrated, perform stereo calibration to obtain the 3D information of the scene. This can be done by OpenCV's stereo calibration function that estimates the relationship between two cameras.

5. [Validate the calibration:](#header--1-5) Finally, validate the calibration by capturing images of the scene using all four cameras and using the obtained parameters to rectify and undistort the images.

*It is important to note that this is a high-level overview and the process can be quite complex. It's recommended to consult the OpenCV documentation and examples for more detailed instructions and guidance. Additionally, it's important to note that the accuracy of the calibration depends on the quality of the calibration pattern, the lighting conditions and the accuracy of the calibration pattern positioning.*

### 1-1: Capture calibration images <a id="header--1-1"></a>

### 1-2: Extract camera parameters <a id="header--1-2"></a>

### 1-3: Synchronize the cameras <a id="header--1-3"></a>

### 1-4: Stereo Calibration <a id="header--1-4"></a>

### 1-5: Validate the calibration <a id="header--1-5"></a>

## 2: Collect training data <a id="header--2"></a>

## 3: Pre-processing <a id="header--3"></a>

## 4: Build the model <a id="header--4"></a>

## 5: Implement the system <a id="header--5"></a>

## 6: Test and Refine the system <a id="header--6"></a>

