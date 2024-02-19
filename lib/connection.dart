import 'package:postgres/postgres.dart';

String url = "otto.db.elephantsql.com";
int port = 5432;
String default_db = "aafnpftg";
String _username = "aafnpftg";
String _password = "R8HE-8mn_Lq9T0XYnPt-_oy3295fmmRD";

String user = "";

var connection = PostgreSQLConnection(url, port, default_db, username: _username, password: _password);

Future<void> initialize() async {
  await connection.open();
}