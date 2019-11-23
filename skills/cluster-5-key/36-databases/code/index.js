//By Kyle Martin, David Kirk, Ayush Upneja

// File reader
const fs = require('fs');
const readline = require('readline');
var count = 0;
var header;

// TingoDB
var Engine = require('tingodb')(),
    assert = require('assert');

// Create DB
var db = new Engine.Db('.', {});
var collection = db.collection("smoke_db");

// Create readstream
const readInterface = readline.createInterface({
    input: fs.createReadStream('smoke.txt'),
    //output: process.stdout,
    console: false
});

// Read each line
readInterface.on('line', function(line) {
    if (count == 0) {
      header = line.split("\t");
      count = count + 1;
    } else {
      var vals = line.split("\t");
      var data = {};
      data[header[0]] = vals[0];
      data[header[1]] = vals[1];
      data[header[2]] = vals[2];
      data[header[3]] = vals[3];
      // Insert data
      collection.insert(data);
    }
});

// Upon close, read the database
readInterface.on('close', function(line) {
  collection.findOne({"ID": "1", "Time": "2000"}, function(err, item) {
    assert.equal(null, err);
    console.log(item);
  })
});
