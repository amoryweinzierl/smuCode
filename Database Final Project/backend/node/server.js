const express = require('express');
const bodyParser = require('body-parser');
const cors = require('cors');
const mysql = require('mysql');
const { log, ExpressAPILogMiddleware } = require('@rama41222/node-logger');

//mysql connection
var connection = mysql.createConnection({
  host: 'backend-db',
  port: '3306',
  user: 'manager',
  password: 'Password',
  database: 'db'
});

//set up some configs for express.
const config = {
  name: 'sample-express-app',
  port: 8000,
  host: '0.0.0.0',
};

//create the express.js object
const app = express();

//create a logger object.  Using logger is preferable to simply writing to the console.
const logger = log({ console: true, file: false, label: config.name });

app.use(bodyParser.json());
app.use(cors({
  origin: '*'
}));
app.use(ExpressAPILogMiddleware(logger, { request: true }));

//Attempting to connect to the database.
connection.connect(function (err) {
  if (err){
    console.log(err);
  }
  logger.info("Connected to the DB!");
});

//Initialize
app.post("/initDB", function (req, res) {

  //Dropping tables

  let query = "DROP TABLE IF EXISTS prescriptions;";
  connection.query(query, (err, result) =>
  {
    if(err) {
      console.log(err);
    }
    else{
      }
  });

  query = "DROP TABLE IF EXISTS drugs"
  connection.query(query, (err, result) =>
  {
    if(err) {
      console.log(err);
    }
    else{
      }
  });

  query = "DROP TABLE IF EXISTS users"
  connection.query(query, (err, result) =>
  {
    if(err) {
      console.log(err);
    }
    else{
      }
  });

  query = "DROP TABLE IF EXISTS sideEffects"
  connection.query(query, (err, result) =>
  {
    if(err) {
      console.log(err);
    }
    else{
      }
  });

  query = "DROP TABLE IF EXISTS symptoms"
  connection.query(query, (err, result) =>
  {
    if(err) {
      console.log(err);
    }
    else{
      }
  });

  query = "DROP TABLE IF EXISTS diseases;"
  connection.query(query, (err, result) =>
  {
    if(err) {
      console.log(err);
    }
    else{
      }
  });

  query = "DROP TABLE IF EXISTS pharmacies;"
  connection.query(query, (err, result) =>
  {
    if(err) {
      console.log(err);
    }
    else{
      }
  });



  //Diseases
	query = "CREATE TABLE diseases (diseaseId int NOT NULL AUTO_INCREMENT,name varchar(45) DEFAULT NULL,PRIMARY KEY (diseaseId))";
  connection.query(query, function(err, result) {
		if (err) {
			console.log(err);
		}
	});

  query = "ALTER TABLE diseases AUTO_INCREMENT = 6000;"
  connection.query(query, function(err, result) {
    if (err) {
      console.log(err);
    }
  });

  //SideEffects

	query = "CREATE TABLE sideEffects (sideEffectId int NOT NULL AUTO_INCREMENT,name varchar(45) DEFAULT NULL,PRIMARY KEY (sideEffectId))";
  connection.query(query, function(err, result) {
		if (err) {
			console.log(err);
		}
	});

  query = "ALTER TABLE sideEffects AUTO_INCREMENT = 4000;"
  connection.query(query, function(err, result) {
    if (err) {
      console.log(err);
    }
  });

  //symptoms

	query = "CREATE TABLE symptoms (symptomId int NOT NULL AUTO_INCREMENT,name varchar(45) DEFAULT NULL,PRIMARY KEY (symptomId))";
  connection.query(query, function(err, result) {
		if (err) {
			console.log(err);
		}
	});

  query = "ALTER TABLE symptoms AUTO_INCREMENT = 5000;"
  connection.query(query, function(err, result) {
    if (err) {
      console.log(err);
    }
  });

  //pharmacies
  query = "CREATE TABLE pharmacies (pharmacyId int NOT NULL AUTO_INCREMENT,name varchar(45) DEFAULT NULL,PRIMARY KEY (pharmacyId))";
  connection.query(query, function(err, result) {
		if (err) {
			console.log(err);
		}
		else {res.status(200).send("Pharmacy table created succesfully")}
	});

  query = "ALTER TABLE pharmacies AUTO_INCREMENT = 7000;"
  connection.query(query, function(err, result) {
    if (err) {
      console.log(err);
    }
  });

  //users

  query = "CREATE TABLE `users` (`id` INT NOT NULL AUTO_INCREMENT,`name` VARCHAR(100),  `email` VARCHAR(50), `password` VARCHAR(500), PRIMARY KEY (`id`), UNIQUE INDEX `id_UNIQUE` (`id` ASC), specialist tinyint, dob DATE); ";
  connection.query(query, (err, result) => {
    if(err) {
      console.log("Errpr creaing parent user", err);
      res.redirect('/'); }
  })
  query = "ALTER TABLE users AUTO_INCREMENT = 1000;";
  connection.query(query, (err, result) => {
    if(err) {
      console.log(err);
      res.status(400);}
  })

  //Drugs

	query = "CREATE TABLE drugs (drugId int NOT NULL AUTO_INCREMENT,name varchar(45) DEFAULT NULL,description varchar(500) DEFAULT NULL,price INT DEFAULT NULL,sideEffectId int DEFAULT NULL,diseaseId int DEFAULT NULL,symptomId int DEFAULT NULL, pharmacyId int DEFAULT NULL, PRIMARY KEY (drugId),KEY fk_drugs_1_idx (sideEffectId),KEY fk_drugs_2_idx (diseaseId),KEY fk_drugs_3_idx (symptomId), KEY fk_drugs_4_idx (pharmacyId), CONSTRAINT fk_drugs_1 FOREIGN KEY (sideEffectId) REFERENCES sideEffects (sideEffectId),CONSTRAINT fk_drugs_2 FOREIGN KEY (diseaseId) REFERENCES diseases (diseaseId),CONSTRAINT fk_drugs_3 FOREIGN KEY (symptomId) REFERENCES symptoms (symptomId), CONSTRAINT fk_drugs_4 FOREIGN KEY (pharmacyId) REFERENCES pharmacies (pharmacyId))";

	connection.query(query, function(err, result) {
		if (err) {
			console.log(err);
		}
  });

  //Prescriptions

  connection.query("create table prescriptions(`prescriptionId` INT NOT NULL AUTO_INCREMENT, userId int default NULL, drugId int default null, oldPrescription tinyint, primary key (prescriptionId), key fk_prescriptions_1_idx (drugId), key fk_prescriptions_2_idx (userId), constraint fk_prescription_1 foreign key (drugId) references db.drugs (drugId), constraint fk_prescription_2 foreign key (userId) references db.users (id))",
    function(err, result, fields) {
      if (err) {
        console.log(err);
        throw err;
      }
    });

    query = "ALTER TABLE prescriptions AUTO_INCREMENT = 2000;"
    connection.query(query, function(err, result) {
      if (err) {
        console.log(err);
      }
    });

});

//GET /
app.get('/', (req, res) => {
  res.status(200).send('Go to 0.0.0.0:3000.');
});


//connecting the express object to listen on a particular port as defined in the config object.
app.listen(config.port, config.host, (e) => {
  if (e) {
    throw new Error('Internal Server Error');
  }
  logger.info(`${config.name} running on ${config.host}:${config.port}`);
});


//API ROUTES
app.get("/login", function (req, res) {
  var returnId;
    let query = "select * from users where email = '" + req.query.email + "' and password = '" + req.query.password + "' limit 1;";
    connection.query(query, function(err, rows, field) {
      console.log("req", req.query);
      if(rows == null  ||rows.length == 0 || err){
        logger.error("INVALID");
        res.status(400);
      }
      else{
        console.log('LOGGED IN');
        returnId = rows[0].id;
      }
      res.status(200).json({
        "id": returnId
      })
    })
});

app.post("/addUser", function (req, res) {
  let query = "insert into users (id, name, email, password) values(" + ` NULL, '${req.body.name}', '${req.body.email}', '${req.body.password}'`+ ")";
  connection.query(query, (err, result) => {
    if(err) {
      console.log(err);
      logger.error("failed adding a user");
      res.status(400);
    }
  })
  var returnId;
  query = "SELECT * FROM users WHERE NAME = '" + req.body.name + "' limit 1;"
  connection.query(query, (err,rows,fields) => {
    if(err){
      res.status(400);
    }
    else{
      returnId = rows[0].id;
    }
  res.status(200).json({
    "id": returnId
  })
});
});

// GET persciptions for user
app.get('/usersprescriptions', function (req, res) {
  let query = "SELECT p.prescriptionID, p.oldPrescription, d.price, d.name, d.description AS DrugDescription,"
  query += " di.name AS DiseaseDescription, s.name AS SymptomDescription, se.name AS SideEffectDescription, ph.name AS PharmacyName"
  query += " from prescriptions p INNER JOIN drugs d ON p.drugId = d.drugId INNER JOIN diseases di ON d.diseaseId = di.diseaseId";
  query += " INNER JOIN symptoms s ON d.symptomId = s.symptomId INNER JOIN sideEffects se ON"
  query += " d.sideEffectId = se.sideEffectId INNER JOIN pharmacies as ph ON d.pharmacyId = ph.pharmacyId where userId = " + req.query.userId;
  console.log(query);
  connection.query(query, (err,rows, result) => {
    if(err) {
      console.log(err);
      logger.error("failed getting a prescription");
      res.status(400);
    }else{
      res.status(200).json({
              "data" : rows
            })
    }

  })
});

app.get('/users/:id', function (req, res) {
  connection.query("SELECT * FROM users WHERE id = ?", [req.params['id']], function (err, result, fields) {
    if (err)
      console.log(err);
    else
    {
      return res.status(200).json({
        "user": result
      })// Result in JSON format
    }
  });
});







app.get('/getDrugId/:id', function (req, res) {
  connection.query("SELECT * FROM drugs WHERE drugId = ?", [req.params['id']], function (err, result, fields) {
    if (err)
      console.log(err);
    else
    {
      return res.status(200).json({
        "drug": result
      })// Result in JSON format
    }
  });
});


app.put("/updateDrug", function (req, res) {
console.log(req.body.diseaseId)
  var query= "UPDATE drugs SET name = " + req.body.id + ", diseaseId = "+ req.body.diseaseId + ", pharmacyId = " + req.body.pharmacyId + ", symptomId = " +req.body.symptomId+ ", sideEffectId = " +req.body.sideEffectId +", description = " +req.body.description+", price = " + req.body.price + "WHERE drugId = " + req.body.drugId;
  console.log('here');
  connection.query("UPDATE drugs SET name = ?, diseaseId = ?, pharmacyId = ?, symptomId = ?, sideEffectId = ?, description = ?, price = ? WHERE drugId = ?",
  [req.body.name, req.body.diseaseId, req.body.pharmacyId, req.body.symptomId, req.body.sideEffectId, req.body.description, req.body.price,req.body.id],
  function (err, result, fields) {

    if (err) {
      console.log(err);
      throw err;
    }
    else
    console.log(result);
      res.end(JSON.stringify(result));

  });

});







app.put("/updateUser", function (req, res) {

  console.log(req.body.id);
  connection.query("UPDATE users SET name = ?, email = ?, password = ?, specialist = ?, dob = ? WHERE id = ?",
  [req.body.name, req.body.email, req.body.password, req.body.specialist, req.body.dob, req.body.id],
  function (err, result, fields) {

    if (err) {
      console.log(err);
      throw err;
    }
    else
    console.log(result);
      res.end(JSON.stringify(result));

  });

});

app.put("/updatePrescription", function (req, res) {
  console.log("API updatePrescription");
  console.log(req.body.id);
  connection.query("UPDATE prescriptions SET oldPrescription = ? WHERE prescriptionId = ?",
  [req.body.pastPrescription, req.body.id],
  function (err, result, fields) {
   if (err) {
    console.log(err);
    throw err;
   }
   else
   console.log(result);
    res.end(JSON.stringify(result));
  });


 });


app.post("/addPrescription", function (req, res) {
  let query = "insert into prescriptions (prescriptionId, userId, drugId, oldPrescription) values(" + ` NULL, '${req.body.userId}', '${req.body.drugId}'`+ ", 0)";
  connection.query(query, (err, result) => {
    if(err) {
      console.log(err);
      logger.error("failed adding a prescription");
      res.status(400);
    }
    var i = 5;
    res.status(200).json({
      "data" : i
    })
  })
});









app.get("/searchPrescription", function (req, res) {
  let query = "SELECT *  from prescriptions where userId = " + req.query.userId +  " AND  drugId = " + req.query.drugId;
  console.log(query);
  connection.query(query, (err,rows, result) => {
    if(err) {
      console.log(err);
      logger.error("failed adding a perscription");
      res.status(400);
    }
    var i = 0;
    if(rows[0] == undefined)
    {
      res.status(200).json({
        "data" : i
      })
    }
    else if(rows[0].oldPrescription == 1)
    {
      i = i+2;
      res.status(200).json({
        "data" : i,
        "prescription" : rows[0]
      })
    }
    else
    {
      i = i + 1;
      res.status(200).json({
        "data" : i
      })
    }

  })
});


app.get("/getSymptoms", function (req, res) {
  let query = "Select * from symptoms";
  connection.query(query, (err, rows, feild) => {
    if(err) {
      console.log(err);
      logger.error("failed getting a symptom");
      res.status(400);
    }
    else{
      res.status(200).json({
        "data": rows
      })
    }
  })
});

app.get("/getPharmacies", function (req, res) {
  let query = "Select * from pharmacies";
  connection.query(query, (err, rows, feild) => {
    if(err) {
      console.log(err);
      logger.error("failed getting a pharmacy");
      res.status(400);
    }
    else{
      res.status(200).json({
        "data": rows
      })
    }
  })
});
app.get("/searchUser", function (req, res) {
  let query = "Select * from users where email = " + req.query.email;
  connection.query(query, (err, rows, feild) => {
    if(err) {
      console.log(err);
      logger.error("failed getting a user");
      res.status(400);
    }
    else{
      res.status(200).json({
        "data": rows
      })
    }
  })
});
app.get("/getSideEffects", function (req, res) {
  let query = "Select * from sideEffects";
  connection.query(query, (err, rows, feild) => {
    if(err) {
      console.log(err);
      logger.error("failed getting a sideEffects");
      res.status(400);
    }
    else{
      res.status(200).json({
        "data": rows
      })
    }
  })
});
app.get("/getDiseases", function (req, res) {
  let query = "Select * from diseases";
  connection.query(query, (err, rows, feild) => {
    if(err) {
      console.log(err);
      logger.error("failed getting a diseases");
      res.status(400);
    }
    else{
      res.status(200).json({
        "data": rows
      })
    }
  })
});


app.get("/getDrugs", function(req, res) {

  let whereClause = req.query.where;
  console.log(whereClause);

  let query = "SELECT d.drugId, d.name, d.description AS DrugDesc, se.name AS SideEffectName, dis.name AS DiseaseName, s.name AS SymptomName, p.name AS PharmacyName, CONCAT('$',d.price) as price from drugs d INNER JOIN sideEffects se ON d.sideEffectID = se.sideEffectId INNER JOIN diseases dis ON d.diseaseId = dis.diseaseId INNER JOIN symptoms s ON d.symptomId = s.symptomId INNER JOIN pharmacies p ON d.pharmacyId = p.pharmacyId " + whereClause;
  connection.query(query, function (err, result, fields) {
    if (err){
      throw err;
      console.log(err);
    }
    else
      res.end(JSON.stringify(result)); // Result in JSON format
    //res.send(result)
  });

});

