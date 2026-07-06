
/*
    __    _ _ __     __  _                    
   / /_  (_|_) /_   / /_(_)___ ___  ___  _____
  / __ \/ / / __/  / __/ / __ `__ \/ _ \/ ___/
 / / / / / / /_   / /_/ / / / / / /  __/ /    
/_/ /_/_/_/\__/   \__/_/_/ /_/ /_/\___/_/     
                                                                       
_________________________________________________________________________________
A High Intensity Interval Training Timer (HIIT) for exercise
using the built in LED for Arduino Uno/Nano/etc.  Simply plug in
the Arduino, and you'll get the following 10 minute HIIT workout:
_________________________________________________________________________________
Routine:

1. 5 seconds flashing to show start of workout.
2. 1 minute warmup, displayed with slow flashes.
3. 30 seconds high intensity flashes, then 1 minute slow flashes. Repeats 5 times.
4. 1 minute warm down, displayed with the LED ON, turning off every 2.5 seconds.
5. Final flashes for 5 seconds to indicate end of work out
__________________________________________________________________________________
  */

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  // Intro: Flashes for 5 seconds to inform user of start
  for (int i = 0; i < 25; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
  }
}

void loop() {
  // 1. WARMUP: First 2 minutes (LED flashes every 2.5 seconds)
  for (int i = 0; i < 48; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
    digitalWrite(LED_BUILTIN, LOW);
    delay(2300);
  }

  // 2. INTERVALS: 30s Quick + 60s Slow (Repeated 5 times total). 
  // Change '5' to '6' to add extra interval)
  for (int repeat = 0; repeat < 5; repeat++) {
    
    // Part A: 30-second Quick Phase
    // First 25 seconds (50ms ON, 50ms OFF)
    for (int i = 0; i < 250; i++) {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(50);
      digitalWrite(LED_BUILTIN, LOW);
      delay(50);
    }
    // Final 5 seconds (25ms ON, 25ms OFF) - blinks quicker to show upcoming change
    for (int i = 0; i < 100; i++) {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(25);
      digitalWrite(LED_BUILTIN, LOW);
      delay(25);
    }

    // Part B: 60-second Slow Phase (Flash every 2.5 seconds)
    // 24 cycles * 2.5 seconds = 60 seconds total
    for (int i = 0; i < 24; i++) {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(200);                     // Quick flash on
      digitalWrite(LED_BUILTIN, LOW);
      delay(2300);                    // Rest of the 2.5s cycle off
    }
  }

  // 3. COOLDOWN: Final 1 minute
  // First 55 seconds: Stay lit, but blink OFF briefly every 2.5 seconds
  // (22 cycles * 2.5 seconds = 55 seconds)
  for (int i = 0; i < 22; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(2350);                    // Lit for most of the 2.5s
    digitalWrite(LED_BUILTIN, LOW);
    delay(150);                     // Brief 150ms dip off
  }
  
  // Last 5 seconds: Flash quickly (50ms ON, 50ms OFF * 50 reps = 5 seconds)
  for (int i = 0; i < 50; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(50);
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);
  }

  // Stop the timer
  while (true) {
    digitalWrite(LED_BUILTIN, LOW);
  }
}