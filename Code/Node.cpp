#include "Node.h"

// Initialising the node
// int S is the data value of the node
void Node::initNode(int S)
{
  node_x = (PLAY_X_START + 50 * dice(PLAY_X_WIDTH / 50));
  node_y = (PLAY_Y_START + 50 * dice(PLAY_Y_HEIGHT / 50));
  node_circle.reset(node_x, node_y, NODE_SIZE);
  node_circle.setColor(COLOR("yellow"));
  node_circle.setFill(false);
  node_bg_circle.reset(node_x, node_y, NODE_SIZE);
  node_bg_circle.setColor(COLOR("black"));
  node_bg_circle.setFill(false);
  node_data.reset(node_x, node_y, S);
  // node_data.scale(4);
  node_data.setColor(COLOR("black"));
  addPart(&node_data);
  addPart(&node_circle);
  addPart(&node_bg_circle);
  node_looped = false;
}

void Node::setFill(bool flag)  // Used to set the whole color of the node
{
  node_circle.setFill(flag);
  node_bg_circle.setColor(COLOR("black"));
}

void Node::changeColor(Color c)   // Used to change the color of the node
{
  node_circle.setColor(c);
  node_circle.setFill(true);
  node_bg_circle.setColor(COLOR("black"));
}

void Node::addAngle(double angle_deg)
{
  release_angle_deg += angle_deg;
  if (release_angle_deg < MIN_RELEASE_ANGLE_DEG)
  {
    release_angle_deg = MIN_RELEASE_ANGLE_DEG;
  }
  if (release_angle_deg > MAX_RELEASE_ANGLE_DEG)
  {
    release_angle_deg = MAX_RELEASE_ANGLE_DEG;
  }
  bool paused = true, rtheta = true;
  if(paused && rtheta) return;
  // reset_all(node_x, node_y, speed, release_angle_deg, node_ax, node_ay, paused, rtheta);
} // End Node::addAngle()

void Node::addSpeed(double arg_speed)
{
  speed += arg_speed;
  if (speed < MIN_RELEASE_SPEED)
  {
    speed = MIN_RELEASE_SPEED;
  }
  if (speed > MAX_RELEASE_SPEED)
  {
    speed = MAX_RELEASE_SPEED;
  }
  bool paused = true, rtheta = true;
  if(paused && rtheta) return;
  // reset_all(node_x, node_y, speed, release_angle_deg, node_ax, node_ay, paused, rtheta);
}