// This first example, maintaining tradition, prints a "Hello World" message.
// Furthermore it shows:
//     - Using the Sample utility functions as a base for the application
//     - Adding a Text element to the graphical user interface
//     - Subscribing to and handling of update events

#include "Scripts/Utilities/Sample.as"

void Start()
{
    // Execute the common startup for samples
    SampleStart();

    // Create "Hello World" Text
    CreateText();

    // Set the mouse mode to use in the sample
    SampleInitMouseMode(MM_FREE);

    // Finally, hook-up this HelloWorld instance to handle update events
    SubscribeToEvents();
	
	anl::CKernel k();
	anl::CNoiseExecutor vm(k);
	
	anl::CExpressionBuilder eb(k);
	anl::CInstructionIndex ii=eb.eval("valueBasis(3,rand)*2-1");
	
	anl::SRGBA col=vm.evaluateColor(0,0.1,ii);
	Print(col.r);
	
	Print(vm.evaluateScalar(0,0,ii));
	
	anl::CArray2Dd img(256,256);
	anl::map2D(0, img, k, anl::SMappingRanges(), 0, ii);
	img.scaleToRange(0.0,1.0);
	Print(img.getMin());
	Print(img.getMax());
	anl::saveDoubleArray("testthing.png", img);
}

void CreateText()
{
    // Construct new Text object
    Text@ helloText = Text();

    // Set String to display
    helloText.text = "Hello World from Urho3D!";

    // Set font and text color
    helloText.SetFont(cache.GetResource("Font", "Fonts/Anonymous Pro.ttf"), 30);
    helloText.color = Color(0.0f, 1.0f, 0.0f);

    // Align Text center-screen
    helloText.horizontalAlignment = HA_CENTER;
    helloText.verticalAlignment = VA_CENTER;

    // Add Text instance to the UI root element
    ui.root.AddChild(helloText);
}

void SubscribeToEvents()
{
    // Subscribe HandleUpdate() function for processing update events
    SubscribeToEvent("Update", "HandleUpdate");
}

void HandleUpdate(StringHash eventType, VariantMap& eventData)
{
    // Do nothing for now, could be extended to eg. animate the display
}

// Create XML patch instructions for screen joystick layout specific to this sample app
String patchInstructions =
        "<patch>" +
        "    <add sel=\"/element/element[./attribute[@name='Name' and @value='Hat0']]\">" +
        "        <attribute name=\"Is Visible\" value=\"false\" />" +
        "    </add>" +
        "</patch>";