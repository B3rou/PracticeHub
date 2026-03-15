# Console Item Catcher

A fast-paced, console-based arcade game built with C#. The objective is simple: control your character to catch falling items before the time runs out, while avoiding console input lag through a custom game loop architecture.

> [!NOTE]
> Roughly speaking, you use the arrow keys to move around and catch falling items. For the algorithm: every 5 frames, objects move one line down. Instead of clearing the entire console, I just print a blank space (" ") over old positions for better UX. To separate session logs, the system creates a unique file with its initial timestamp for every match. Your goal is to reach 50 points before the 30-second timer runs out. For a detailed explanation, keep reading.

## How to Play
* **Movement:** Use `Left Arrow` and `Right Arrow` to move the player (`@`).
* **Quit:** Press `ESC` to exit the game at any time.
* **Goal:** Reach **50 points** within **30 seconds**.
* **Scoring:** Every caught item grants 5 points.

---

## Architecture & Algorithm (Under the Hood)

### 1. Game Loop
To prevent input lag while keeping the falling items at a playable speed, the game decouples the rendering/input logic from the physics logic:
* **The Frame Rate:** The main `while` loop runs extremely fast (`Thread.Sleep(20)`), creating roughly 50 FPS. This ensures the game registers keyboard inputs instantly without freezing.
* **The Physics Tick:** The falling items do not move every frame. Instead, a `fallCounter` dictates that items only drop one line down every 5 frames. This allows the player to move swiftly without the items crashing to the ground at lightspeed.

### 2. Collision Detection & Anti-Ghosting
The game treats the console terminal as a 2D coordinate grid (X,Y). 
Collision is calculated by constantly comparing the `Player (X,Y)` against the `Item (X,Y)` coordinates in real-time. Once a collision is detected, the item is destroyed. To prevent visual "ghosting" (where a caught item leaves a trail on the screen), the rendering engine specifically targets the object's current and previous coordinates to overwrite them with empty spaces.

### 3. Safe Collection Modification (Reverse Iteration)
When items hit the ground or are caught by the player, they must be removed from the dynamic `List<GameObject>`. 
To avoid `IndexOutOfRangeException` and skipping elements-a common bug when iterating and deleting from the same array-the update logic uses a **Reverse For Loop**:

```csharp
for (int i = items.Count - 1; i >= 0; i--) { ... }
```

By iterating from the end of the list to the beginning, deleting an item only shifts the indices of the *already processed* items, keeping the loop safe and highly optimized.

### 4. File I/O & Debug Logging

The game features an integrated tracking system. Every major state change (Key presses, player movement, item spawns, object translations, and collisions) is continuously appended to a local `game_log_<date>.txt` file in real-time, providing a complete debug trail of the session.

---

## How to Run

### Method 1: The Modern Way (.NET 10+)
Thanks to the new "File-based Apps" feature in .NET 10, you no longer need to deal with project scaffolding or `.csproj` files to run single-file games!

1. Ensure you have the **.NET 10 SDK** (or newer) installed.
2. Download the `Program.cs` file.
3. Open your terminal in the same directory and simply execute:

```bash
dotnet run Program.cs
```

### Method 2: Older SDKs (.NET 9 and below)

If you are on an older version of .NET, standard project scaffolding is the most reliable way to play:

1. Create a new empty console project from your terminal:
```bash
dotnet new console -n ConsoleItemCatcher
```

2. Navigate into the newly created directory:
```bash
cd ConsoleItemCatcher
```

3. Replace the contents of the auto-generated `Program.cs` file with the code from this repository.
4. Build and run the game:
```bash
dotnet run
```

**Developer:** B3rou