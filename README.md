# Sheep_Counter (using TinkerCad)

I have used two ultrasonic sensors which are connected to an Arduino Uno, which detect the number of sheeps inside the fenced area.

The first sensor with trg1 and echo1 (trigger and echo pins respectively) detects sheeps which are entering through the gate.                      
			The second sensor with trg2 and echo2 (trigger and echo pins respectively) detects sheeps which are leaving through the gate.

Given Assumptions:
1. Only 1 sheep enters or leaves through the gate at an any point in time.
2. The average time taken by a sheep to enter or leave through the gate is 700 ms. 
3. The width of the gate is considered to be 150 cm.
