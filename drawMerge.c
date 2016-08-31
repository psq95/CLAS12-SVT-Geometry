
void drawMerge() {
    gSystem->Load("libGeom");
    gSystem->Load("libGdml");
    TGeoManager *geom = TGeoManager::Import("SVTFactory_merge.gdml");

    TList *matList = geom->GetListOfMaterials();
    TIter matNext( matList );
    cout << "setting material transparencies\n";
    int transparencyAir = 80;
    int transparencyShifted = 0;
    while( mat = (TGeoMaterial*) matNext() )
    {
        TString *matName = new TString( mat->GetName() );
        if( matName->Contains("shifted") )
        {
            cout << "shifted " << transparencyShifted;
            mat->SetTransparency( transparencyShifted );
        }
        else
        {
            cout << "default " << transparencyAir;
            mat->SetTransparency( transparencyAir );
        }
        cout << " " << matName->Data() << "\n";
    }
    
    TGeoVolume *top = geom->GetTopVolume();
    //top->SetLineColor( kWhite );
    geom->SetTopVisible();
    
    TObjArray *volList = geom->GetListOfVolumes();
    TIter volNext( volList );
    cout << "setting volume colours\n";
    //cout << "modules red\n";
    
    while( vol = (TGeoVolume*) volNext() )
    {
        vol->SetVisContainers(kFALSE);
        TString *volName = new TString( vol->GetName() );
        if( volName->Contains("module") )
        {
            //cout << "module";
            vol->SetLineColor( kRed );
        }
        else if( volName->Contains("sensorActive") )
        {
            //cout << "sensorActive";
            vol->SetLineColor( kBlue );
        }
        else if( volName->Contains("fiducial") )
        {
            //cout << "fiducial";
            if( volName->Contains("shifted") )
                vol->SetLineColor( kCyan );
            else
                vol->SetLineColor( kGreen );
        }
        else if( volName->Contains("sectorBall") )
        {
            //cout << "fiducial";
            if( volName->Contains("shifted") )
                vol->SetLineColor( kOrange );
            else
                vol->SetLineColor( kRed );
        }
        else
        {
            //cout << "default";
            vol->SetLineColor( kGray );
        }
        //cout << " " << volName->Data() << "\n";
    }

    cout << "VisLevel " << geom->GetVisLevel() << "\n";
    cout << "VisOption " << geom->GetVisOption() << "\n";
    //geom->SetVisLevel( 3 );
    //geom->SetVisOption( 1 );
    //cout << "new VisLevel " << geom->GetVisLevel() << "\n";
    //cout << "new VisOption " << geom->GetVisOption() << "\n";
    top->Draw("ogl");
}
