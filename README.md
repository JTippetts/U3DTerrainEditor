# U3DTerrainEditor
Simple terrain editor built using Urho3D.
Note that this is very much a work in progress. Features come and go without warning or notice. At any given time, things could be just horribly, *horribly* broken. 

##Building
U3DTerrainEditor is built using the [Urho3D](https://github.com/urho3d/Urho3D) engine. Follow the instructions for building Urho3D, and build the engine. Building the U3DTerrainEditor follows a similar process to building Urho3D; execute the cmake batch file of your choice, as detailed in Urho3D building instructions, and specify the parameter `-DURHO3D_HOME=<Path to Urho3D build>` to tell it where to find the engine.

##Running
When building is done, it should create a bin/ folder in your build directory, inside of which will be copied the executable and the data folders. Follow the instructions for [running the Urho3DPlayer](https://urho3d.github.io/documentation/HEAD/_running.html) to run, specifying LuaScripts/terraineditor.lua for the file to execute. For example, to run in a window you would execute `TEdit.exe LuaScripts/terraineditor.lua -w` on Windows. To run in a borderless window, you would execute `TEdit.exe LuaScripts/terraineditor.lua -borderless`. See the Urho3D documentation for other specifiable command-line options, many of which may or may not be relevant depending on the whims of chance and coding.

##Using
Once you have successfully built and run the application (congratulations will be in order, given my tendency to break things horribly as mentioned earlier) you should be presented with a view something like this:

![U3DTerrainEditor first view](https://i.imgur.com/bTXT076.jpg)

Note again that things change quite often, so the actual view you see may be different.

#Basic editing
In the lower left is a toolbar showing the various actions you can perform. Edit Height is chosen by default when first starting. Next to the toolbar, you can see a Brush Options dialog, that allows you to specify the characteristics of the editing brush for the selected tool. Most of the editing brushes have a similar format, with sliders controlling the parameters. Typically, the parameters include *Power*, which determines how strongly the brush is applied; *Radius*, which determines the size of the brush area; *Max*, which caps the brush output to a given level, and *Hardness* which determines the brush sharpness. Go ahead and select Edit Height if it's not already selected, move the cursor to the terrain, and left-click+drag to draw terrain.

![Drawing height](https://i.imgur.com/pAlWdMU.jpg)

Try playing with the sliders. For example, lowering the max and increasing the sharpness can get a result like this:

![Terrain height max](https://i.imgur.com/hABHeKU.jpg)

The Max parameter caps the brush output at a given height, so by adjusting max you adjust the level of the terrain you draw. Drawing takes place at the terrain cursor, which is shown as a fuzzy white dot that follows the surface of the terrain, rather than directly at the mouse cursor. Thus, you may need to sometimes adjust the camera to get a good view of where you want to edit.

#Camera controls
The camera may be adjusted using the scroll wheel to zoom in and out. You can also rotate the view by holding down the middle mouse button and moving the mouse side to side and up and down. The camera will zoom all the way in to ground level at its nearest zoom level, allowing you to see what the terrain looks like from the ground.

#Further editing
If you select *Smooth Height* on the tool bar, you have access to a tool for applying a smoothing effect. Smoothing omits the *Max* parameter, using only *Power*, *Radius* and hardness.

If you select Terrain on the toolbar, a new brush opens up with a palette of terrain textures that can be applied.

![Editing terrain](https://i.imgur.com/E7swxva.jpg)

Click on a texture swatch to begin editing that layer. On each swatch you can see a small up-arrow button. Clicking on that button will pull up a dialog that allows you to change the diffuse texture and normalmap to use for that layer. It will also allow you to change the layer scaling, or tiling size, of the texture.

![Layer settings](https://i.imgur.com/HR4krHu.jpg)

In the toolbar there are also 3 selections for editing Masks. The editor provides 3 mask layers that can be painted to, and which can be used to mask off areas from change. Each of the editing brushes (Edit Height, Smooth Height, Terrain) has a checkbox to force using one or more of the Mask layers. You can use Masks to protect certain areas from change. Projects currently in progress will also allow masks to be inverted, once the UI changes are made to select them.

As an example, you can select Mask 1, and paint an area.

![Editing Mask](https://i.imgur.com/Tgk2jcZ.jpg)

Then you can open the Edit Height brush again, select Use Mask 1, and paint elevation.

![Painting with a mask](https://i.imgur.com/jBqiqVu.jpg)

The mask value scales the power of the brush, so you can see that at the edges of the mask, where the mask value softens, some terrain editing happens, but in the areas where the mask is full power the terrain is protected. The masks are rendered as Red, Green and Blue overlays on the terrain. In the works are some UI changes that will allow showing/hiding the masks from view.

(Will finish this later.)
