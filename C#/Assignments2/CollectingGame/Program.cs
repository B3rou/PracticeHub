using System;
using System.Collections.Generic;
using System.Threading;
using System.IO;
using System.Diagnostics;

class GameObject
{
    public int X;
    public int Y;
    public char Symbol;
}

class Program
{
    static string date = DateTime.Now.ToString("yyyy-MM-dd_HH-mm-ss");
    static string logFile = $"game_log_{date}.txt";

    static void LogToFile(string message)
    {
        File.AppendAllText(logFile, message + Environment.NewLine);
    }

    static void Main()
    {
        // Initial console setup
        Console.Clear();
        Console.CursorVisible = false;
        
        // Lock window size to prevent visual glitches during gameplay
        try 
        {
            Console.SetWindowSize(80, 30);
            Console.SetBufferSize(80, 30);
        }
        catch { /* Ignored for cross-platform compatibility */ }
        
        bool isGameRunning = true;
        int playerX = Console.WindowWidth / 2;
        int playerY = Console.WindowHeight - 2;
        int previousPlayerX = playerX;

        int score = 0;
        int targetScore = 50;

        Random random = new Random();
        List<GameObject> items = new List<GameObject>();
        
        // Timing controllers
        int spawnCounter = 0;
        int fallCounter = 0; 

        Stopwatch timer = new Stopwatch();
        timer.Start();

        File.WriteAllText(logFile, "--- GAME STARTED ---" + Environment.NewLine);

        // Initial draw
        Console.SetCursorPosition(playerX, playerY);
        Console.Write("@");

        // MAIN GAME LOOP
        while (isGameRunning)
        {
            // ---------------------------------------------------------
            // 1. INPUT
            // ---------------------------------------------------------
            if (Console.KeyAvailable)
            {
                ConsoleKey keyInfo = Console.ReadKey(true).Key;
                LogToFile($"INPUT -> key={keyInfo} playerX={playerX} playerY={playerY}");
                previousPlayerX = playerX;

                if (keyInfo == ConsoleKey.LeftArrow) playerX--;
                if (keyInfo == ConsoleKey.RightArrow) playerX++;
                if (keyInfo == ConsoleKey.Escape) isGameRunning = false;
            }

            // Screen boundary checks for player
            if (playerX < 0) playerX = 0;
            if (playerX >= Console.WindowWidth) playerX = Console.WindowWidth - 1;
            
            if (previousPlayerX != playerX) 
                LogToFile($"UPDATE -> playerMoved playerX={playerX} playerY={playerY}");

            // ---------------------------------------------------------
            // 2. COLLISION DETECTION
            // ---------------------------------------------------------
            for (int i = items.Count - 1; i >= 0; i--)
            {
                if (items[i].X == playerX && items[i].Y == playerY)
                {
                    score += 5;
                    LogToFile($"COLLISION -> score={score} sembol={items[i].Symbol}");
                    
                    Console.SetCursorPosition(items[i].X, items[i].Y);
                    Console.Write(" ");
                    if (items[i].Y - 1 >= 0)
                    {
                        Console.SetCursorPosition(items[i].X, items[i].Y - 1);
                        Console.Write(" ");
                    }

                    items.RemoveAt(i);
                }
            }

            // ---------------------------------------------------------
            // 3. UPDATE (Item Spawning & Movement)
            // ---------------------------------------------------------
            spawnCounter++;
            if (spawnCounter >= 15)
            {
                spawnCounter = 0;
                
                // Item Pool
                char[] symbolPool = { '*', 'O', '%', '&' };
                
                GameObject newItem = new GameObject
                {
                    X = random.Next(0, Console.WindowWidth),
                    Y = 0,
                    Symbol = symbolPool[random.Next(0, symbolPool.Length)] 
                };
                items.Add(newItem);
                LogToFile($"UPDATE -> itemSpawned x={newItem.X} y={newItem.Y} sembol={newItem.Symbol}");
            }

            fallCounter++;
            if (fallCounter >= 5) 
            {
                fallCounter = 0;
                for (int i = items.Count - 1; i >= 0; i--)
                {
                    GameObject currentItem = items[i];
                    int oldY = currentItem.Y;
                    currentItem.Y++;

                    LogToFile($"UPDATE -> objectMoved x={currentItem.X} oldY={oldY} newY={currentItem.Y}");

                    // Remove item if it hits the ground
                    if (currentItem.Y >= Console.WindowHeight)
                    {
                        Console.SetCursorPosition(currentItem.X, oldY);
                        Console.Write(" ");
                        items.RemoveAt(i);
                    }
                }
            }

            // ---------------------------------------------------------
            // 4. GAME OVER LOGIC
            // ---------------------------------------------------------
            if (timer.Elapsed.TotalSeconds >= 30 || score >= targetScore)
            {
                isGameRunning = false;
                string endReason = score >= targetScore ? "Won" : "TimeOut";
                LogToFile($"GAME OVER -> sebep={endReason} finalScore={score} sure={timer.Elapsed.TotalSeconds:F1}s");
            }

            // ---------------------------------------------------------
            // 5. DRAW
            // ---------------------------------------------------------
            // UI Overlay
            Console.SetCursorPosition(0, 0);
            Console.Write($"Score: {score} | Time Left: {30 - (int)timer.Elapsed.TotalSeconds}s  ");

            // Draw Player
            if (previousPlayerX != playerX)
            {
                Console.SetCursorPosition(previousPlayerX, playerY);
                Console.Write(" ");
                Console.SetCursorPosition(playerX, playerY);
                Console.Write("@");
            }

            // Draw Items
            if (fallCounter == 0) 
            {
                foreach (GameObject item in items)
                {
                    if (item.Y - 1 >= 0)
                    {
                        Console.SetCursorPosition(item.X, item.Y - 1);
                        Console.Write(" ");
                    }
                    
                    if (item.Y < Console.WindowHeight)
                    {
                        Console.SetCursorPosition(item.X, item.Y);
                        Console.Write(item.Symbol);
                    }
                }
            }

            // Frame rate control (~50 FPS)
            Thread.Sleep(20); 
        }

        // Cleanup and Exit
        timer.Stop();
        Console.Clear();
        Console.WriteLine($"--- GAME OVER ---");
        Console.WriteLine($"Final Score: {score}");
        Console.WriteLine($"Time Elapsed: {timer.Elapsed.TotalSeconds:F1} seconds");
        Console.WriteLine($"Debug info saved to game_log_{date}.txt.");
    }
}