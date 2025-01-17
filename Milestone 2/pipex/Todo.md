# Pipex

## Understand Unix Processes in C
 - Great playlist [Unix Processes in C](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)

## Guide For pipex
 - Read this guide from GitBook [pipex](https://42-cursus.gitbook.io/guide/rank-02/pipex)


 ## One tips that im using to reduce memory errors (douple free, leaks, ...)
 When you allocate memory for an array, you must get the elements number that you want to store into it, and iterate throught the array and initialize eack block by NULL

 ### Infinite lock screen
 - while true; do ft_lock ;done
