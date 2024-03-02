import 'package:flutter/material.dart';
import 'package:application/style.dart' as style;
import 'package:application/connection.dart' as db;

class DeviceRegisterPage extends StatefulWidget {
  const DeviceRegisterPage({super.key});

  @override
  State<DeviceRegisterPage> createState() => _DeviceRegisterPageState();
}

class _DeviceRegisterPageState extends State<DeviceRegisterPage> {
  
  String username = db.user;
  List<String> deviceList = [];
  
  // The text editing controller is used to capture user input and pass it into
  // local copies of data through dialog boxes
  late TextEditingController controller;

  @override
  void initState() {
    super.initState();

    initializeDevices();

    controller = TextEditingController();
  }

  @override
  void dispose() {
    controller.dispose();

    super.dispose();
  }

  void initializeDevices() async {
    List<List<dynamic>> results = await db.connection.query("SELECT mcu_id FROM registry WHERE username='$username'");
    
    setState(() {
      deviceList.clear();
      
      for (final row in results) {
        deviceList.add(row[0]);
      }
    });
  }
  
  void addDevice(String newDevice) async {
    print("Adding device $newDevice");

    await db.connection.query("INSERT INTO registry (mcu_id, username) VALUES ('$newDevice', '$username')");
    
    setState(() {
      deviceList.add(newDevice);
    });
    
  }
  
  void removeDevice(String device) async {
    await db.connection.query("DELETE FROM registry WHERE mcu_id='$device'");
  }

  Future<String?> openTextEntryDialog() => showDialog<String>(
    context: context,
    builder: (context) => AlertDialog(
      title: Text("Enter MAC Address", style: style.textStyle),
      backgroundColor: style.backgroundAccent,
      content: TextField(
        decoration: InputDecoration(
          hintText: "Enter MAC address here",
          hintStyle: style.subtextStyle,
        ),
        controller: controller,
        onSubmitted: (_) => submitText(),
        style: style.textStyle,
      ),
      actions: [
        TextButton(
          onPressed: submitText,
          style: TextButton.styleFrom(
            foregroundColor: style.mainColor,
          ),
          child: const Text("ADD DEVICE"),
        )
      ],
    ),
  );

  void submitText() {
    Navigator.of(context).pop(controller.text);

    controller.clear();
  }

  void errorNullDialog() => showDialog(
    context: context,
    builder: (context) => AlertDialog(
      backgroundColor: style.backgroundColor,
      title: Text("Error: Please enter a value", style: style.textStyle),
      actions: [
        TextButton(
          onPressed: close,
          style: TextButton.styleFrom(
            foregroundColor: style.mainColor,
          ),
          child: const Text("OK"),
        )
      ],
    ),
  );

  void close() {
    Navigator.of(context).pop(context);
  }

  @override
  Widget build(BuildContext context) {

    return Scaffold(
      backgroundColor: style.backgroundColor,
      appBar: AppBar(
        // Here we take the value from the MyHomePage object that was created by
        // the App.build method, and use it to set our appbar title.
        title: const Text("Register Device"),
        backgroundColor: style.mainColor,
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            Padding(
              padding: const EdgeInsets.all(20.0),
              child: FloatingActionButton.extended(
                heroTag: "Add",
                onPressed: () async {
                  final newDevice = await openTextEntryDialog();
                  if (newDevice == null || newDevice.isEmpty) {
                    errorNullDialog();
                    return;
                  }

                  addDevice(newDevice);
                },
                label: Text("Add Device", style: style.buttonTextStyle),
                backgroundColor: style.mainColor,
                foregroundColor: style.backgroundColor,
              ),
            ),
            const Text("Devices:"),
            Expanded(
              child: ListView.builder(
                itemCount: deviceList.length,
                itemBuilder: (BuildContext context, int index) {
                  String text = deviceList[index];
                  return Card(
                    child: ListTile(
                      title: Text("Name: $text"),
                      trailing: IconButton(
                        icon: const Icon(Icons.delete),
                        onPressed: () {

                          removeDevice(deviceList[index]);

                          setState(() {
                            deviceList.removeAt(index);
                          });
                        },
                      ),
                    )
                  );
                }
              ),
            ),
          ],
        ),
      ),

      // The bottom navigation bar allows for easy access to the three main pages of the application
      bottomNavigationBar: BottomAppBar(
        // This padding makes the icons look cleaner and increase readability for the user
        padding: const EdgeInsets.all(5.0),

        // This color specification allows dark mode to function, as the theme settings in main
        // are only set when the application is initially started
        color: style.backgroundAccent,

        // The Row widget lines all of the children contained into a row
        child: Row(
          // Centers the icons in the navigation bar
          mainAxisAlignment: MainAxisAlignment.center,

          // Each TextButton calls the Navigator to navigate between the three main pages
          // The currently active page is given an onPressed value which is blank and are given a different color
          // This prevents the user from repeatedly pressing the button and causing performance issues
          // Pages which are not active use pushReplacementNamed to push the new page onto the navigator stack
          // The internal names for each page are defined by the developer and can be found in main.dart
          children: [
            TextButton(
              onPressed: () {
                Navigator.pushReplacementNamed(context, '/settings');
              },
              child: Icon(Icons.settings, size: 50, color: style.mainColor),
            ),
            TextButton(
              onPressed: () {
                Navigator.pushReplacementNamed(context, '/main');
              },
              child: Icon(Icons.house, size: 50, color: style.mainColor),
            ),
            TextButton(
              onPressed: () {},
              child: Icon(Icons.bar_chart, size: 50, color: style.selectedColor),
            ),
          ],
        ),
      ),// This trailing comma makes auto-formatting nicer for build methods.
    );
  }
}
