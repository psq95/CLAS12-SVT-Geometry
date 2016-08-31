package VolumeExporter;

import javax.xml.parsers.ParserConfigurationException;

public class VolumeExporterFactory
{
	public static IGdmlExporter createGdmlFactory() throws IllegalArgumentException
	{
		try {
			return new GdmlFile();
		}
		catch( ParserConfigurationException e )
		{
			e.printStackTrace();
		}
		return null;
	}
}
