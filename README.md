# 42-philosopher
42-Network-Projects
 ## Introduction
This is one of the best projects I've built so far during my cursus.

The 42-Philosopher problem is a classic computer science problem that serves as a practical exercise in concurrency and synchronization,
So, after this project, I have a big knowledge of computer science and process management.

## Compilation
you can run this program for testing and checking how i manage it.

-Enetr to the philo directory and run make to compile it:
```sh
  cd philo
  make
```

## Usage

./philo num_of_philo time_to_die time_to_eat time_to_sleep [limit_of_meals](optional)

## philo testing
Do not test with more than 200 philosophers.

Do not test with time_to_die or time_to_eat or time_to_sleep set to values lower than 60 ms.

Test ```1 800 200 200```. The philosopher should not eat and should die.

Test ```5 800 200 200```. No philosopher should die.

Test ```5 800 200 200 7```. No philosopher should die and the simulation should stop when every philosopher has eaten at least 7 times.

Test ```4 410 200 200```. No philosopher should die.

Test ```4 310 200 100```. One philosopher should die.

Test ```4 200 200 205```. One philo should die.

Test ```200 800 200 200```. No one should die.

Test with any values of your choice to verify all the requirements. Ensure philosophers die at the right time, that they don't steal forks, and so forth.

# Finally
  That is all for this first part, this first part is implemented using thread and mutex {multithreading}, and i'm working for the second part using process and semaphore {multitasking}, you can find it in other repo "philo_bonus". good luck for everyone.
