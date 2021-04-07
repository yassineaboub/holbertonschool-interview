#!/usr/bin/node

const request = require('request');
const args = process.argv.slice(2);

request.get(`https://swapi-api.hbtn.io/api/films/${args}/`, async (err, response, body) => {
  const char = JSON.parse(body).char;
  for (const ch of char) {
    const chrc = await new Promise((resolve, reject) => {
      request(ch, (error, resp, bodys) => {
        if (error) {
          reject(error);
        } else {
          resolve(JSON.parse(bodys).name);
        }
      });
    });
    console.log(chrc);
  }
});
