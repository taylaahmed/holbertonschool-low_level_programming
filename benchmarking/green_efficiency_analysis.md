# Measurement Methodology

Within this experiment the unit of measurement used was seconds, to create a clear and understandable comparision of processing times. Time (seconds) is a measurment of Intervals between the start of the program running and the end of the program running. This is a form of Qualitative data, as we are using numbers to quanitfy and conpare data. 

# Observed Performance Differences

Within task 01.Algorithmic Efficiency Comparison there was a clear difference in processing speed between Naive and Single-pass. Within my testing there was a difference in processing time of over 1.6 seconds. Naive function averaged: 1.732437 seconds while Single-pass averaged: 0.000068 seconds. Within the Naive function there are two 'for' loops while the Single-pass only had one. Additionally, the Naive function had one more variable comparted to Single-pass. These choices making the function longer added to its processing time and efficiency. 

Within 02.Controlled Instrumentation Experiment, the sentiment that short code led to faster processing was less apparent. PROCESS takes less time to process compared to BUILD_DATA which was unexpected when referencing the prior experiment with PROCESS taking an average of 0.000165 and BUILD_DATA taking an average of 0.000312. As this was a multi-step function this could display that the function used or the starting step of multi-step functions takes the most processing time while still supporting the importance of concise code. From these tasks all parts of the process were relatively efficient, with the BUILD_DATA step consistently taking more time to process. 

# Relation Between Runtime and Energy Consumption

This paragram was written with reference to article: https://hmnshudhmn24.medium.com/the-silent-byte-why-your-codes-carbon-footprint-matters-and-how-to-shrink-it-a434b7ef420c

While any piece of code is running it need to be supported by internal computer components as well as external servers and network. Any one program will run internally through CPU/GPU cycles - where complex algorithms will require more power, RAM - large files and memory allocation will use energy, Reading and writing to disk takes energy. Externally programs use networks - where every byte requires power and other infostructure. More bytes and complexity will lead to an increase the programs runtime effecting power usage from multiple internal and external processes. 

# Limitations of the Experiment

This experiment was extremely isolated, run locally on my personal laptops and may not be truly indicative of a more thorough study. For this experiment to be more indicative of code length leading to processing time more experiments would need to be conducting using a number of different codes to text the same principle. In summery this experiment was simply too small scale to create any real/concrete assumptions. 

# Practical Engineering Takeaway

A practical engineering takeaway from this exercise was to be more aware of code length and efficiency when creating functions. I need to attempt to be more consistent with reviewing code I write to see if there is any unused or unnecessary functions or variables. Another takeaway was the consideration of not only time efficiency but how this translates to energy efficiency. Within current day of AI integration being energy efficient and creating energy efficient programs becomes increasingly important. 