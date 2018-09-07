# keyboard_receiver
Receive key pressed in keyboard and publish to ROS topic. 
This implementation uses OpenCV `waitKey()` function to catch keyboard events. 
## Usage
```
rosrun keyboard_receiver keyboard_receiver_node
```
Click on the image window, then any key pressed will be published to topic.
## Published topics
Topic: "key_pressed"

Type: "std_msgs/Int64"
