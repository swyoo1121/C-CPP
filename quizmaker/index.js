const axios = require('axios');
const readline = require('readline');

// Set up your OpenAI API credentials
const apiKey = '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';

// Function to extract the main topic word
async function extractMainTopic(input) {
  try {
    const apiUrl = 'https://api.openai.com/v1/completions';

    // Compose the data for the API request
    const requestData = {
      prompt: `Extract the main topic word from the following input:\n\n${input}\n\nMain topic word:`,
      max_tokens: 7, // Increase max_tokens to ensure complete word retrieval
      n: 1,
      stop: '\n',
      model: 'text-davinci-003',
    };

    // Make the API request
    const response = await axios.post(apiUrl, requestData, {
      headers: {
        'Content-Type': 'application/json',
        'Authorization': `Bearer ${apiKey}`
      }
    });

    // Extract the main topic word from the API response
    const mainTopicWord = response.data.choices[0].text.trim();

    return mainTopicWord;
  } catch (error) {
    console.error('Error:', error);
    throw error;
  }
}

// Create readline interface
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

// Prompt the user for input
rl.question('Enter the input paragraph: ', async (input) => {
  try {
    const mainTopic = await extractMainTopic(input);
    console.log('Main topic:', mainTopic);
  } catch (error) {
    console.error('Error:', error);
  } finally {
    // Close the readline interface
    rl.close();
  }
});
