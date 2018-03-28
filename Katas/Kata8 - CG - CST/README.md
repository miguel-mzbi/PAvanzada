# Kata 8 - Coding Games - "Coders Strike Back"

Miguel Angel Montoya Z.

The code here reached Bronze-133rd

## Problem

Win the race.

### Rules

The circuit of the race is made up of checkpoints. To complete one lap, your vehicle (pod) must pass through each checkpoints in order and back through the start. The first player to reach the starting checkpoint on the final lap wins.

The pods work as follows:

- To pass a checkpoint, the center of a pod must be inside the radius of the checkpoint.
- To move a pod, you must print a target destination point followed by a thrust value. Details of the protocol can be found further down.
- The thrust value of a pod is its acceleration and must be between 0 and 100.
- You can use 1 acceleration boost in the race, you need only replace the thrust value by the BOOST keyword.
- The pods have a circular force-field around their center, with a radius of 400 units, which activates in case of collisions with other pods.

## Breakdown

The problem here is to maintain an equilibrium between de acceleration and the angular momentum than the pod will have on rotation. As the pod approaches to a goal, it must start to decelerate in case it has to rotate towards the next one.

### Solution

1. On each iteration, first the angle of the pod and the goal is checked, if it's bigger than 90°, the pod wont accelerate, to let itself rotate.
2. If the pod it's less than 600 units from the goal, it decreases the thrust to 25.
3. If the pod it's less than 900 units from the goal, it decreases the thrust to 50.
4. If the pod it's less than 600 units from the goal, it decreases the thrust to 75.
5. If in any of the previous cases the angle is too sharp, it reduces the thrust to it's half.
6. If the pod it's more than 2000 units from the goal, the boost it's available and the angle isn't sharp, it uses the boost.
7. Else, the thrust is 100.