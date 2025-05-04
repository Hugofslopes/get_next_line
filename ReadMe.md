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

<details>
	<summary>Get the line and save it to the statig variable</summary>
<ol>
    <li>Call <b>copy_fd( )</b> to read from the provided file descriptor.</b>
	<ol>
		<li>Alocate memory fot hte <b>buffer</b>> variable to storage the character read</b></li>
		<li><b>Call read( )</b> with the parameters <b>fd</b> (the file descriptor from which it will be reading), <b>buffer</b> (which is the array of characters that we allocate memory for) and BUFFER_SIZE (the number of characters to be read).</li>
		<li>It will be on a loop that continues until reaches the end of the file or finds the <b>'\n'</b> (meaning a new line).</li>
		<li>Call <b>add_to_strgs( )</b> on each iteration of the loop to add the content read to the static variable.</li>
		<li>Call <b>check_for_new_line( )</b> to check if the static variable already contains the new line.
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