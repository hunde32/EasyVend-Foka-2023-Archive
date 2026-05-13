const express = require("express");
const fs = require("fs");
const cors = require('cors');
const { type } = require("os");

const app = express();

app.use(express.static("public"));
app.use(express.json());
app.use(cors());

app.get("/", function (request, response) {
  response.sendFile(__dirname + "/index.html");
});

app.post("/", function (req, res) {
    saveData(req.body);
    res.send("Hello")
});

app.listen(3000, function () {
    console.log("Server running")
});

function saveData(newData) {
  fs.readFile("order.json", 'utf8', (err, data) => {
    if (err) {
      throw err;
    }
  
    // Parse the JSON data into a JavaScript object.
    const jsonObject = JSON.parse(data);
    let order = [];
    jsonObject.forEach(element => {
      order.push(element)
    });
    order.push(newData[0]);

    fs.writeFileSync("order.json", JSON.stringify(order), 'utf-8');

    // Do something with the JSON object.
    // console.log(jsonObject);
  });

  

}

