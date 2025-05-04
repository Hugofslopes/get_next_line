<p align="center">
    <img src="https://www.42porto.com/wp-content/uploads/2024/08/42-Porto-Horizontal.png" alt="Pipex Image" />
</p>
<h1 align="center">Get next line</h1>
<p align="center">
    <img src="https://github.com/user-attachments/assets/ca0ec9d2-b97d-4e3c-b646-5a03cf7bad6d" alt="Image" />
</p>

## Summary
<p>
    <b>Get next line </b> is a 42 school project with the goal of reading the next file from a given file descriptor. It should compile with the flag <b>-D</b>, which will define the buffer size for reading."
</p>

## Code Phases
<details>
	<summary>Parsing</summary>
<ol>
    <li>First, we check if the file descriptor <b>(fd)</b> is smaller than 0. This happens because the first possible fd is <b>0</b>, which is standard input. <b>1</b> means <b>standard output</b> and <b>2</b> means <b>standard error</b>. After that, all other fds are created by the user, as shown in the example I provided in the main function using <b>open( )</b> to open some test files.</b></li>
	<li>Check if the macro <b>BUFFER_SIZE</b> is greater than 0, because its value will determine the number of characters we will read.</li>
</ol>
</details>


## Code Setup
<p>
    <b>Step 1:</b> Clone the repository
</p>

    git clone https://github.com/Hugofslopes/get_next_line

<p>
    <b>Step 2:</b> Open the terminal on the repo folder and write
</p>

    make

<p>
    <b>Step 3:</b> Execute main
</p>

    ./main

<p>
    <b>Step 4:</b> Execute main bonus
</p>

    make bonus ; ./mainbonus

## Improvements
<p>
    
</p>